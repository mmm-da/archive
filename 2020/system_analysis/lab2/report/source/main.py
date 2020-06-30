import numpy as np
import math 
import matplotlib.pyplot as pl
import scipy.integrate as integrate
import scipy.optimize as optimize
k = 19.833333333333336
a = 1
b = 2
count_of_num = 2000
arr = []
result_arr = []

def f(x):
    return (x**5+x**2+7)
def f_(x):
    return (x**5+x**2+7)/k

def prob_num(xi,v):
    s1 = integrate.quad(f,a,xi)[0]
    #print('integral =',s1,' v =',v,"int-v =",s1/k-v," xi =",xi)
    return (s1/k - v)


for i in range(0,count_of_num):
    arr.append(np.random.random_sample())

for i in arr:
    def t(x):
        return prob_num(x,i)
    solve = optimize.fsolve(t,b)
    result_arr.append(solve[0])
    #print("xi =",solve)
    np.round(solve,3,solve)
    #print("xi =",solve)
    #print('---')
x_axis = np.linspace(a,b) 
fig,ax = pl.subplots(1,1)
pl.plot(x_axis,np.apply_along_axis(f_,0,x_axis))
pl.hist(result_arr,30,density=True)
pl.show()