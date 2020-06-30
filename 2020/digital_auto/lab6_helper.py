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
        result.append([
            i+1,
            args,
            f(f_v9,f_v12,args),
            f(f_v10,f_v12,args),
            f(f_v11,f_v12,args)
            #int(f(f_v16,f_v19,args)),
            #int(f(f_v17,f_v19,args)),
            #int(f(f_v18,f_v19,args)),
        ])
    return result

def temp_table(table):
    result = []
    for i in table:
        if(i[2]!='-'):
            result.append([
                set([i[0]]),
                i[1],
                i[2],
                i[3],
                i[4],
            ])
    return result

def latex_sdnf_func(impl_list):
    result_str = ""
    for i in impl_list:
        result_str = result_str+"( "
        pos = 1
        for j in i[1]:
            if (j == '1'):
                result_str = result_str + 'x_' + str(pos)
            elif(j == '0'):
                result_str = result_str + r'\overline '+'x_'+str(pos)
            pos = pos + 1
        result_str = result_str + r" ) \lor "
    return result_str[0:-6]

def step_one_matrix(table):
# i,j x1 x2 x3 x4 x5
    result_arr = []
    for i in range(0,len(table)):
        for j in range(i,len(table)):
            f_str_i = table[i][2] + table[i][3] + table[i][4]
            f_str_j = table[j][2] + table[j][3] + table[j][4]
            print(f_str_i,f_str_j)
            if(f_str_i!=f_str_j):
                current_item = []
                current_item.append(table[i][0] | table[j][0])
                x1 = bool(int(table[i][1][0])) != bool(int(table[j][1][0]))
                x2 = bool(int(table[i][1][1])) != bool(int(table[j][1][1]))
                x3 = bool(int(table[i][1][2])) != bool(int(table[j][1][2]))
                x4 = bool(int(table[i][1][3])) != bool(int(table[j][1][3]))
                x5 = bool(int(table[i][1][4])) != bool(int(table[j][1][4]))
                current_item.append(str(int(x1)))
                current_item.append(str(int(x2)))
                current_item.append(str(int(x3)))
                current_item.append(str(int(x4)))
                current_item.append(str(int(x5)))
                result_arr.append(current_item)
    return result_arr

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

table_head = ["№","$x_1x_2x_3x_4x_5$","f1","f2","f3"]
table = truth_table(gen_bin_vector())
print(tabulate(table,table_head,tablefmt="simple"))

sdnf_table = temp_table(table)
print(tabulate(sdnf_table,table_head,tablefmt="simple"))
sdnf_table = step_one_matrix(sdnf_table)
table_head = ["№","x1","x2","x3","x4","x5"]
print(tabulate(sdnf_table,table_head,tablefmt="simple"))
sdnf_table = step_one_simplify(sdnf_table)
table_head = ["№","x1","x2","x3","x4","x5"]
print(tabulate(sdnf_table,table_head,tablefmt="simple"))

#impl_list = impl_combination(sdnf_table)
#impl_list_head = ["№","$x_1x_2x_3x_4x_5$","Простая импликанта?","Признаки принадлежности"]
#for i in impl_list:
#    print(tabulate(i,impl_list_head,tablefmt="simple"))

#simple_impl_list = simple_impl(impl_list)
#simple_impl_list = impl_group(simple_impl_list)
#print('Список простых импликант')
#print(tabulate(simple_impl_list,impl_list_head,tablefmt="simple"))

#print('\nТаблица простых импликант')
#impl_table = implicant_table(simple_impl_list,table)
#print(tabulate(impl_table[1],impl_table[0],tablefmt="latex"))

#print(latex_sknf_func(simple_impl_list))
#result = factor_sknf_table(simple_impl_list)
#print(tabulate(result[1],result[0],tablefmt="fancy_grid"))
