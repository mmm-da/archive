import numpy as np
import random
from math import exp
from collections import Counter
import cProfile
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from PySide2.QtCore import Signal,QObject,Slot
from PySide2.QtWidgets import QMessageBox

class SimulatedAnnealing(QObject):
    def __init__(self, t_min, t_max, alpha, n, iterations):
        QObject.__init__(self)
        # Входные параметры
        self.t_min = t_min
        self.t_max = t_max
        self.t_current = t_max
        self.alpha = alpha
        self.n = n
        self.iterations = iterations

        self.start_solution = self.initialize_solution()                
        self.start_energy = self.check_conflicts(self.start_solution)   

        self.current_solution = self.start_solution.copy()                    
        self.current_energy = self.start_energy                       

        self.best_solution = self.start_solution.copy()                        
        self.best_energy = self.start_energy                           

        self.stats = {
            "iterations": [0],
            "bad_solutions": [0],
            "temperature": [self.t_max],
            "energy": [self.start_energy]
        }

    def check_conflicts(self, solution):
        dx = [-1, 1, -1, 1]
        dy = [-1, 1, -1, 1]
        board = []
        for i in range(0, self.n):
            str = []
            for j in range (0, self.n):
                if solution[i] == j:
                    str.append(1)
                else:
                    str.append(0)
            board.append(str)
        conflicts = 0
        for i in range(0, len(solution) - 1):
            x = i
            y = solution[i]
            for j in range(0, 3):
                tmpx = x
                tmpy = y
                while 1:
                    tmpx = tmpx + dx[j]
                    tmpy = tmpy + dy[j]
                    if tmpx < 0 or tmpx >= self.n or tmpy < 0 or tmpy >= self.n:
                        break
                    if board[tmpx][tmpy] == 1:
                        conflicts += 1
        return conflicts


    def initialize_solution(self):
        solution = []
        for i in range (0, self.n):
            r = random.randint(0, self.n-1)
            while r in solution:
                r = random.randint(0, self.n-1)
            solution.append(r)
        return solution

    def generate_swappos(self):
        v = random.sample(range(0, self.n - 1), 2)
        return v[0], v[1]

    def calculate(self):
        bad_solutions = 0
        total_iterations = 0
        while self.t_current > self.t_min:
            for current_iteration in range(self.iterations - 1):
                solution = self.current_solution.copy()
                energy = self.current_energy
                x, y = self.generate_swappos()
                solution[x], solution[y] = solution[y], solution[x]
                energy = self.check_conflicts(solution)
                if energy < self.current_energy:
                    self.current_solution = solution.copy()
                    self.current_energy = energy
                else:
                    p = exp( -(energy - self.current_energy)/self.t_current)
                    if p > random.random():
                        self.t_current *= self.alpha
                        self.current_solution = solution.copy()
                        self.current_energy = energy
                        bad_solutions += 1
                if (self.current_energy < self.best_energy):
                    self.best_solution = self.current_solution.copy()
                    self.best_energy = self.current_energy

                self.stats['iterations'].append(total_iterations)
                self.stats['bad_solutions'].append(bad_solutions)
                self.stats['temperature'].append(self.t_current)
                self.stats['energy'].append(self.current_energy)
                total_iterations += 1

                if self.current_energy == 0:
                    msg = QMessageBox()
                    msg.setIcon(QMessageBox.Information)
                    msg.setWindowTitle("Успешно")
                    msg.setText("Решение с нулевой энергией найдено")
                    msg.exec_()
                    return {
                        "array": self.best_solution,
                        "energy": self.best_energy
                    }
        return {
            "array": self.best_solution,
            "energy": self.best_energy
        }
        

    @Slot()
    def plot(self):
        blue_patch = mpatches.Patch(color='blue', label='Температура')
        red_patch = mpatches.Patch(color='red', label='Кол-во принятых плохих решений')
        green_patch = mpatches.Patch(color='green', label='Энергия лучшего решения')
        print(self.stats)
        plt.subplot(311)
        plt.legend(handles=[red_patch,blue_patch,green_patch])
        plt.plot(
            self.stats['iterations'],
            self.stats['temperature'],
            color="blue"
        )
        plt.subplot(312)
        plt.plot(
            self.stats['iterations'],
            self.stats['bad_solutions'],
            color="red"
        )
        plt.subplot(313)
        plt.plot(
            self.stats['iterations'],
            self.stats['energy'],
            color="green"
        )
        plt.show()