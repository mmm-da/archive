import math
import random
import numpy
import matplotlib.pyplot as pt
from scipy.stats import norm

#Заданные параметры для нормально распределенных случайных величин
#Среднее арифметическое
mean = 1
#Среднеквадратичное отклонение
std = 0.1

def get_gause_num(count_of_probe):
    num_arr = []
    for i in range(count_of_probe):
        num_arr.append(random.random())
    
    arr_mean = numpy.mean(num_arr) 
    arr_despertion = numpy.var(num_arr)
    return (numpy.sum(num_arr) - arr_mean) * arr_despertion * math.sqrt(2)

num_arr = []
for i in range(count_of_gause_num):
    num_arr.append(get_gause_num(num_per_gause_num))

gause_mean = numpy.mean(num_arr)
gause_std = numpy.std(num_arr)

normalize = lambda x:(x-gause_mean)/gause_std

norm_arr = numpy.vectorize(normalize)(num_arr)
gause_arr = norm_arr * std + mean 

#Вывод параметров полученных случайных чисел
print("Среднее арифметическое - ",numpy.mean(gause_arr))
print("Дисперсия - ",numpy.var(gause_arr))
print("Среднеквадратичное отклонение - ",numpy.std(gause_arr))

x_axis = numpy.linspace(norm.ppf(0.01),norm.ppf(0.99),0)
fig,ax = pt.subplots(1,1)
ax.plot(x_axis,norm.pdf(x_axis, mean, std), label='norm pdf')
ax.hist(gause_arr,30,alpha = 0.5,density=True)
pt.show()
