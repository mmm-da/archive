from binVectors import gen_bin_vector_5 as gen_bin_vector
from tabulate import tabulate

def del_dup(list):
    res = [] 
    for i in list: 
        if i not in res: 
            res.append(i) 
    return res

def diff_pos(str_a,str_b):
    list_a=list(str_a)    
    list_b=list(str_b)
    i=0
    while(i<len(list_a)):
        if(list_a[i]!=list_b[i]):
            return i
        i = i + 1
        
def hamming_dist(s1, s2):
    assert len(s1) == len(s2)
    return sum(ch1 != ch2 for ch1, ch2 in zip(s1, s2)) 

def truth_table(vector):
    result = []
    for i in range(0,len(vector)):
        args = vector[i][0]
        sch = test_schema(args)
        result.append([
            i+1,
            args,
            f(f_v9,f_v12,args),
            int(sch[0]),
            f(f_v10,f_v12,args),
            int(sch[1]),
            f(f_v11,f_v12,args),
            int(sch[2])
            #int(f(f_v16,f_v19,args)),
            #int(f(f_v17,f_v19,args)),
            #int(f(f_v18,f_v19,args)),
        ])
    return result


def search_str(arr,str):
    for index,i in enumerate(arr):
        if i[1]==str[1] and i[2]==str[2] and i[3]==str[3] and i[4]==str[4] and i[5]==str[5]:
            return index
    return None

def step_one_simplify(table):
    result_arr = []
    for i in table:
        if search_str(result_arr,i) == None:
            result_arr.append(i)
    return result_arr

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
    if not f2(str_val):
        return '-'
    else:
         return str(int(f1(str_val)))

def test_schema(str_val):
    x1 = bool(int(str_val[0]))
    x2 = bool(int(str_val[1]))
    x4 = bool(int(str_val[3]))
    x5 = bool(int(str_val[4]))

    z1 = not x1 and x4
    z2 = not x2 and x1
    z3 = x1 and not x5
    z4 = not x2 and not x4
    z5 = x4 and not x2
    z6 = x2 and x4

    u1 = z1 and x2 
    u2 = z1 and x5
    u3 = z4 and x1
    u4 = z5 and x5
    u5 = z2 and x4
    u6 = z2 and not x5
    u7 = z6 and not x5
    u8 = z3 and x4
    u9 = z3 and not x4

    v3 = u1 or u2
    v4 = u4 or u5
    v6 = u3 or u6
    v8 = u7 or u8

    v1 = v3 or v6
    v2 = v3

    v5 = v1 or u3  
    v7 = v4 or v2

    f1 = v4 or v5 
    f2 = v1
    f3 = v7 or u8
    return (f1,f2,f3)
table_head = ["№","$x_1x_2x_3x_4x_5$","f1",'sch_f1',"f2",'sch_f2',"f3",'sch_f3']
table = truth_table(gen_bin_vector())
print(tabulate(table,table_head,tablefmt="simple"))
