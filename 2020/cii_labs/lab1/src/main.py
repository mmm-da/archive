import sys
from simulated_annealing import SimulatedAnnealing
from PySide2.QtWidgets import (
    QApplication,
    QLabel,
    QPushButton,
    QVBoxLayout,
    QHBoxLayout,
    QGridLayout,
    QFormLayout,
    QLineEdit,
    QWidget,
    QProgressBar,
    QFrame,
)
from PySide2.QtCore import SIGNAL,Slot, Qt, QMargins,Signal,QObject

"""
    VBoxLayout
        FormLayout
            NForm
            TmaxForm
            TminForm
            StepFrom
            AlphaForm
            RunButton
            PlotButton
        VBoxLayout
            ProgressBar
            GridLayout
                ChessElement
                ChessElement
                ...
                ...
                ChessElement

"""
# величины на графике
# 1. кол-во принятых плохих решений
# 2. температура
# 3. энергия лучшего решения в процессе работы программы


class ChessCell(QWidget):
    def __init__(self):
        QWidget.__init__(self)
        self.setContentsMargins(0, 0, 0, 0)
        self.layout = QVBoxLayout()
        self.layout.setContentsMargins(0, 0, 0, 0)
        self.label = QLabel("")
        self.label.setFrameStyle(QFrame.Panel | QFrame.Raised)
        self.setStyleSheet("padding: 15px; margin: 0px")
        self.layout.addWidget(self.label)
        self.setLayout(self.layout)

    def __repr__(self):
        return self.label.text()

    def set(self):
        self.setStyleSheet(
            "padding: 15px; margin: 0px; " + "background-color: #000000;"
        )

    def off(self):
        self.setStyleSheet(
            "padding: 15px; margin: 0px;" + "background-color: #FFFFFF;"
        )

class ChessBoard(QWidget):
    def __init__(self):
        QWidget.__init__(self)
        self.setVisible(False)
        self.layout = QGridLayout()
        self.layout.setContentsMargins(0, 0, 0, 0)
        self.n = 0
        self.board = []
        self.setLayout(self.layout)

    def clear(self):
        for row in self.board:
            for cell in row:
                self.layout.removeWidget(cell)
                row.remove(cell)
            self.board.remove(row)

    def show_solution(self, solution):
        self.n = len(solution)
        self.board = []
        for i in range(self.n):
            temp_list = []
            for j in range(self.n):
                temp_list.append(ChessCell())
            self.board.append(temp_list)
        for x, y in enumerate(solution):
            self.board[y][x].set()
        for index_y, i in enumerate(self.board):
            for index_x, cell in enumerate(i):
                self.layout.addWidget(cell, index_y, index_x)
        self.setVisible(True)


class Application(QWidget):
    solution_ready = Signal(list)
    def __init__(self):
        QWidget.__init__(self)

        self.layout = QHBoxLayout()

        self.inputLayout = QVBoxLayout()
        self.formLayout = QFormLayout()

        self.nForm = QLineEdit("5")
        self.tmaxForm = QLineEdit('100')
        self.tminForm = QLineEdit('0.1')
        self.alphaForm = QLineEdit('0.98')
        self.stepForm = QLineEdit('1000')
        self.runButton = QPushButton("Запустить")
        self.plotButton = QPushButton("Показать график")

        self.visualLayout = QVBoxLayout()
        self.progressBar = QProgressBar()
        self.progressBar.setVisible(False)
        self.chessBoard = ChessBoard()

        self.formLayout.addRow("N:", self.nForm)
        self.formLayout.addRow("Tmax:", self.tmaxForm)
        self.formLayout.addRow("Tmin:", self.tminForm)
        self.formLayout.addRow("alpha:", self.alphaForm)
        self.formLayout.addRow("Кол-во шагов:", self.stepForm)

        self.inputLayout.addLayout(self.formLayout)
        self.inputLayout.addWidget(self.runButton)
        self.inputLayout.addWidget(self.progressBar)
        self.inputLayout.addWidget(self.plotButton)

        self.layout.addLayout(self.inputLayout)
        self.layout.addLayout(self.visualLayout)
        self.setLayout(self.layout)
        
        QObject.connect(self.runButton,SIGNAL('pressed()'),self.run_solve)

    @Slot()
    def run_solve(self):
        self.visualLayout.removeWidget(self.chessBoard)
        self.progressBar.setRange(0,int(self.stepForm.text()))
        self.progressBar.setVisible(True)
        self.solver = SimulatedAnnealing(
            float(self.tminForm.text()),
            float(self.tmaxForm.text()),
            float(self.alphaForm.text()),
            int(self.nForm.text()),
            int(self.stepForm.text())
        )
        QObject.connect(self.solver,SIGNAL('stepSolve(int)'),self.progressBar.setValue)
        QObject.connect(self.plotButton,SIGNAL('pressed()'),self.solver.plot)
        solution = self.solver.calculate()
        print(solution)
        self.progressBar.setVisible(False)
        self.chessBoard = ChessBoard()
        self.visualLayout.addWidget(self.chessBoard)
        self.chessBoard.show_solution(solution['array'])
        QObject.disconnect(self.solver,SIGNAL('stepSolve(int)'),self.progressBar.setValue)
if __name__ == "__main__":
    app = QApplication(sys.argv)

    widget = Application()
    widget.show()

    sys.exit(app.exec_())