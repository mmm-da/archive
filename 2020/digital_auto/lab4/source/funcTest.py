from binVectors import gen_bin_vector_5 as gen_bin_vector
from tabulate import tabulate

def truth_table(vector,f):
    result = []
    for i in range(0,len(vector)):
        result.append([
            i+1,
            vector[i][0],
            int(f(vector[i][0])),
        ])
    return result

def bad_truth_table(vector,f,var,val):
    result = []
    for i in range(0,len(vector)):
        result.append([
            i+1,
            vector[i][0],
            int(f(vector[i][0],var,val)),
        ])
    return result

def function(str_val):
    x1 = bool(int(str_val[0]))
    x2 = bool(int(str_val[1]))
    x3 = bool(int(str_val[2]))
    x4 = bool(int(str_val[3]))
    x5 = bool(int(str_val[4]))
    z1 = x1 and (not x2)
    z2 = x1 and (not x5) 
    z3 = (not x1) and x3
    z4 = x2 and x4
    z5 = (not x3) and (not x4)

    u1 = z3 and x5
    u2 = z4 and (not x1)
    u7 = z2 and (not x4)
    u4 = z1 and (not x4)
    u5 = z5 and x1
    u6 = z2 and (not x2)
    u3 = z1 and (not x3)

    v1 = u1 or u2
    v2 = u3 or u4
    v3 = u5 or u6
    v4 = v1 or u7
    v5 = v2 or v3
    f = v4 or v5
    return f

def bad_schema(vars, fault_gate, fault_val):
    x1 = bool(int(fault_val)) if fault_gate == 'x1' else bool(int(vars[0]))
    x2 = bool(int(fault_val)) if fault_gate == 'x2' else bool(int(vars[1]))
    x3 = bool(int(fault_val)) if fault_gate == 'x3' else bool(int(vars[2]))
    x4 = bool(int(fault_val)) if fault_gate == 'x4' else bool(int(vars[3]))
    x5 = bool(int(fault_val)) if fault_gate == 'x5' else bool(int(vars[4]))
    z1 = x1 and (not x2)
    z2 = x1 and (not x5) 
    z3 = (not x1) and x3
    z4 = x2 and x4
    z5 = (not x3) and (not x4)

    u1 = z3 and x5
    u2 = z4 and (not x1)
    u7 = z2 and (not x4)
    u4 = z1 and (not x4)
    u5 = z5 and x1
    u6 = z2 and (not x2)
    u3 = z1 and (not x3)

    v1 = u1 or u2
    v2 = u3 or u4
    v3 = u5 or u6
    v4 = v1 or u7
    v5 = v2 or v3
    f = v4 or v5
    return f

def diag_test(var,val):
    table = bad_truth_table(gen_bin_vector(),bad_schema,var,val)
    print("Подаем набор X10")
    if(table[9][2]==1):
        print("Возможные неисправности F2,F6,F8")
        print("Подаем набор X8")
        if(table[7][2]==1):
            print("Возможные неисправности F6,F8")
            print("Подаем набор X2")
            if(table[1][2]==1):
                print("Неисправность определена F6")
            else:
                print("Неисправность определена F8")
        else:
            print("Неисправность определена F2")
    else:
        print("Возможные неисправности F1,F3,F4,F5,F7,F9,F10")
        print("Подаем набор X31")
        if(table[30][2]==1):
            print("Возможные неисправности F1,F3,F7")
            print("Подаем набор X24")
            if(table[23][2]==1):
                print("Возможные неисправности F1,F7")
                print("Подаем набор X11")
                if(table[10][2]==1):
                    print("Неисправность определена F1")
                else:
                    print("Неисправность определена F7")
            else:
                print("Неисправность определена F3")
        else:
            print("Возможные неисправности F4,F5,F9,F10")
            print("Подаем набор X5")
            if(table[4][2]==1):
                print("Неисправность определена F10")
            else:
                print('Возможные неисправности F4,F5,F9')
                print("Подаем набор X7")
                if(table[6][2]==1):
                    print("Неисправность определена F4")
                else:
                    print('Возможные неисправности F5,F9')


table_head = ["№","$x_1x_2x_3x_4x_5$","f"]
table = truth_table(gen_bin_vector(),function)
print(tabulate(table,table_head,tablefmt="simple"))

var_arr = ['x1','x2','x3','x4','x5']

for var in var_arr:
    for val in ['0','1']:
        print("Неисправность "+var+"("+val+")")
        diag_test(var,val)
        print()