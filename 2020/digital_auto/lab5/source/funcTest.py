from binVectors import gen_bin_vector_5 as gen_bin_vector
from tabulate import tabulate

def truth_table(vector):
    result = []
    for i in range(0,len(vector)):
        args = vector[i][0]
        sch = schema(args)
        result.append([
            i+1,
            args,
            int(f(f_v9,f_v12,args)),
            int(sch[0]),
            int(t1_sch_f1(args)),
            int(f(f_v10,f_v12,args)),
            int(sch[1]),
            int(t1_sch_f2(args)),
            int(f(f_v11,f_v12,args)),
            int(sch[2]),
            int(t1_sch_f3(args))
        ])
    return result
def f_v9(str_val):
    x1 = str_val[0]
    x2 = str_val[1]
    x3 = str_val[2]
    x4 = str_val[3]
    x5 = str_val[4]
    return (
        3 < (int(x4 + x5,2) + int(x1 + x2 + x3,2)) < 8 
    ) 

def f_v10(str_val):
    x1 = str_val[0]
    x2 = str_val[1]
    x3 = str_val[2]
    x4 = str_val[3]
    x5 = str_val[4]
    return (
        4 <= (int(x4 + x5,2) + int(x1 + x2 + x3,2)) <= 6 
    ) 

def f_v11(str_val):
    x1 = str_val[0]
    x2 = str_val[1]
    x3 = str_val[2]
    x4 = str_val[3]
    x5 = str_val[4]
    return (
        5 <= (int(x2 + x3,2) + int(x4 + x5 + x1,2)) <= 8 
    ) 

def f_v12(str_val):
    x1 = str_val[0]
    x2 = str_val[1]
    x3 = str_val[2]
    x4 = str_val[3]
    x5 = str_val[4]
    return (
        -2 <= (int(x1 + x2,2) - int(x3 + x4 + x5,2)) <= 1 
    ) 

def f(f1,f2,str_val):
    return f1(str_val) and f2(str_val)

def t1_sch_f1(str_val):
    x1 = bool(int(str_val[0]))
    x2 = bool(int(str_val[1]))
    x3 = bool(int(str_val[2]))
    x4 = bool(int(str_val[3]))
    x5 = bool(int(str_val[4]))
    
    z2 = not x3 and x4 
    z3 = not x1 and x2
    z4 = not x4 and not x5 
    z5 = x1 and x3
    z6 = x1 and not x2
    
    z1 = not x3 and z6

    u1 = z2 and z3
    u4 = z4 and z5
    u2 = z1 and x5
    u3 = z1 and x4

    v1 = u1 or u2
    v2 = u3 or u4

    f = v1 or v2
    return f

def t1_sch_f2(str_val):
    x1 = bool(int(str_val[0]))
    x2 = bool(int(str_val[1]))
    x3 = bool(int(str_val[2]))
    x4 = bool(int(str_val[3]))
    x5 = bool(int(str_val[4]))
    
    z2 = not x2 and x1 
    z3 = not x4 and x5
    z4 = not x3 and x4
    z5 = not x1 and x2
    z6 = x3 and not x4

    z7 = z2 and not x3
    z1 = z2 and not x5

    u1 = z7 and z3 
    u2 = z1 and z4
    u3 = z1 and z6
    u4 = z4 and z5

    v1 = u1 or u2
    v2 = u3 or u4

    f = v1 or v2
    return f

def t1_sch_f3(str_val):
    x1 = bool(int(str_val[0]))
    x2 = bool(int(str_val[1]))
    x3 = bool(int(str_val[2]))
    x4 = bool(int(str_val[3]))
    x5 = bool(int(str_val[4]))
    
    z2 = not x3 and x4 
    z3 = not x1 and x2
    z4 = not x4 and not x5 
    z5 = x2 and x3

    z6 = x1 and z4 
    z1 = x1 and z2

    u1 = z5 and z6
    u2 = z2 and z3
    u3 = not x2 and z1
    u4 = not x5 and z1

    v1 = u1 or u2
    v2 = u3 or u4

    f = v1 or v2
    return f

def schema(str_val):
    x1 = bool(int(str_val[0]))
    x2 = bool(int(str_val[1]))
    x3 = bool(int(str_val[2]))
    x4 = bool(int(str_val[3]))
    x5 = bool(int(str_val[4]))

    z7 = x2 and x5
    z8 = not x3 and x4
    z9 = x1 and not x2
    z10 = x1 and x3

    z4 = x2 and z8
    z5 = not x4 and z10
    z6 = not x3 and z9

    z1 = not x5 and z5
    z2 = x4 and z6
    z3 = x5 and z6

    u1 = not x1 and z4
    u2 = not x5 and z4
    u3 = z3
    u4 = not x4 and z3
    u5 = z2
    u6 = not x5 and z2
    u7 = z1
    u8 = not x2 and z1
    u9 = z5 and z7

    v1 = u1 or u5
    v2 = u3 or u7
    v3 = u1 or u4
    v4 = u6 or u8
    v5 = u2 or u9

    f1 = v1 or v2
    f2 = v3 or v4
    f3 = v1 or v5
    return (f1,f2,f3)
table_head = ["№","$x_1x_2x_3x_4x_5$","f1",'t1_sch_f1','t2_sch_f1',"f2",'t1_sch_f2','t2_sch_f2',"f3",'t1_sch_f3','t2_sch_f3']
table = truth_table(gen_bin_vector())
print(tabulate(table,table_head,tablefmt="simple"))

