#!/bin/python3
import random;
def dots(n):
    for i in range(0, n):
        print(random.randint(0,100),":",random.randint(0,100), sep="")

n = int(input())
print(n)
dots(n)
