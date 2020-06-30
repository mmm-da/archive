import numpy as np
import math 

table_str = "db "
flag = True
amp = 64
for i in range (0,256):
    table_str += ' '+str(int(flag)+127+amp)+'h,'
    flag = not flag
    amp = -amp
print(table_str)