import random 
from math import log1p

def to_cont_exp(value):
    return log1p(-value)

origin_values = []

for i in range(0,50):
    origin_values.append(random.random())

print(origin_values)