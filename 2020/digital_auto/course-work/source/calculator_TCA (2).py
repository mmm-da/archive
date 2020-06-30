# СДНФ получать тут(в настройках опустить знак конъюнкции, в СДНФ первый символ отрицания иногда не копируется - проверять): https://programforyou.ru/calculators/postroenie-tablitci-istinnosti-sknf-sdnf
#формат ввода: отрицание инициализировать!!! в inv_char, буквы t или x, за ними цифра, конъюнктивные термы пишутся слитно, между ними конъюнкиця - kon_char(инициализировать!!!)

inv_char = "!"
kon_char = " ∨ "

Y = [
    "!t1t2t3!x3!x2!x1 ∨ !t1t2t3!x3!x2x1 ∨ !t1t2t3!x3x2!x1 ∨ !t1t2t3!x3x2x1 ∨ !t1t2t3x3!x2!x1 ∨ !t1t2t3x3!x2x1 ∨ !t1t2t3x3x2!x1 ∨ !t1t2t3x3x2x1",
    "!t1!t2t3!x3!x2!x1 ∨ !t1!t2t3!x3!x2x1 ∨ !t1!t2t3!x3x2!x1 ∨ !t1!t2t3!x3x2x1 ∨ !t1!t2t3x3!x2!x1 ∨ !t1!t2t3x3!x2x1 ∨ !t1!t2t3x3x2!x1 ∨ !t1!t2t3x3x2x1 ∨ !t1t2t3!x3!x2!x1 ∨ !t1t2t3!x3!x2x1 ∨ !t1t2t3!x3x2!x1 ∨ !t1t2t3!x3x2x1 ∨ !t1t2t3x3!x2!x1 ∨ !t1t2t3x3!x2x1 ∨ !t1t2t3x3x2!x1 ∨ !t1t2t3x3x2x1 ∨ t1!t2!t3!x3!x2!x1 ∨ t1!t2!t3!x3!x2x1 ∨ t1!t2!t3!x3x2!x1 ∨ t1!t2!t3!x3x2x1 ∨ t1!t2!t3x3!x2!x1 ∨ t1!t2!t3x3!x2x1 ∨ t1!t2!t3x3x2!x1 ∨ t1!t2!t3x3x2x1",
    "!t1!t2t3!x3!x2!x1 ∨ !t1!t2t3!x3!x2x1 ∨ !t1!t2t3!x3x2!x1 ∨ !t1!t2t3!x3x2x1 ∨ !t1!t2t3x3!x2!x1 ∨ !t1!t2t3x3!x2x1 ∨ !t1!t2t3x3x2!x1 ∨ !t1!t2t3x3x2x1 ∨ !t1t2!t3!x3!x2!x1 ∨ !t1t2!t3!x3!x2x1 ∨ !t1t2!t3!x3x2!x1 ∨ !t1t2!t3!x3x2x1 ∨ !t1t2!t3x3!x2!x1 ∨ !t1t2!t3x3!x2x1 ∨ !t1t2!t3x3x2!x1 ∨ !t1t2!t3x3x2x1",
    "!t1!t2t3!x3!x2!x1 ∨ !t1!t2t3!x3!x2x1 ∨ !t1!t2t3!x3x2!x1 ∨ !t1!t2t3!x3x2x1 ∨ !t1t2!t3!x3!x2!x1 ∨ !t1t2!t3!x3!x2x1 ∨ !t1t2!t3!x3x2!x1 ∨ !t1t2!t3!x3x2x1 ∨ !t1t2t3!x3!x2!x1 ∨ !t1t2t3!x3!x2x1 ∨ !t1t2t3!x3x2!x1 ∨ !t1t2t3!x3x2x1 ∨ t1!t2!t3!x3x2!x1 ∨ t1!t2!t3!x3x2x1 ∨ t1!t2!t3x3x2!x1 ∨ t1!t2!t3x3x2x1",
    "!t1!t2!t3!x3!x2!x1 ∨ !t1!t2!t3!x3x2!x1 ∨ !t1!t2!t3x3!x2!x1 ∨ !t1!t2!t3x3x2!x1 ∨ !t1!t2t3x3!x2!x1 ∨ !t1!t2t3x3!x2x1 ∨ !t1!t2t3x3x2!x1 ∨ !t1!t2t3x3x2x1 ∨ !t1t2!t3!x3!x2!x1 ∨ !t1t2!t3!x3!x2x1 ∨ !t1t2!t3!x3x2!x1 ∨ !t1t2!t3!x3x2x1 ∨ !t1t2t3!x3!x2!x1 ∨ !t1t2t3!x3!x2x1 ∨ !t1t2t3!x3x2!x1 ∨ !t1t2t3!x3x2x1",
    "!t1!t2!t3!x3!x2!x1 ∨ !t1!t2!t3!x3!x2x1 ∨ !t1!t2!t3!x3x2!x1 ∨ !t1!t2!t3!x3x2x1 ∨ !t1!t2!t3x3!x2x1 ∨ !t1!t2!t3x3x2x1 ∨ !t1!t2t3!x3!x2!x1 ∨ !t1!t2t3!x3!x2x1 ∨ !t1!t2t3!x3x2!x1 ∨ !t1!t2t3!x3x2x1 ∨ !t1!t2t3x3!x2!x1 ∨ !t1!t2t3x3!x2x1 ∨ !t1!t2t3x3x2!x1 ∨ !t1!t2t3x3x2x1 ∨ !t1t2t3!x3!x2!x1 ∨ !t1t2t3!x3!x2x1 ∨ !t1t2t3!x3x2!x1 ∨ !t1t2t3!x3x2x1 ∨ !t1t2t3x3!x2!x1 ∨ !t1t2t3x3!x2x1 ∨ !t1t2t3x3x2!x1 ∨ !t1t2t3x3x2x1"]

t_num = 3       #количество бит t
x_num = 3       #количество бит x

def parse_func(func_str):
    func = func_str.replace(kon_char, " ")
    res = []
    lst = []
    val =  True
    for i in range(len(func)):
        if func[i] == inv_char:
            val = False
        if func[i] == 't':
            lst.append(val)
            val = True            
        if func[i] == 'x':
            lst.append(val)
            val = True
        if func[i] == ' ':
            res.append(lst)
            lst = []
    res.append(lst)
    return res

def get_implicanta_str(implicanta):
    res_str = ""
    for k in range(len(implicanta)):
        res_str += (inv_char if not(implicanta[k]) else "") + ("t" if (k < t_num) else "x") +  (str(k + 1) if (k < t_num) else str(k+1-t_num))
    return res_str

def get_implicanta_str_2(implicanta, intersec):
    res_str = ""
    for k in range(len(implicanta)):
        if implicanta[k] != 2:
            res_str += (r'\overline ' if implicanta[k] == 0 else "") + ("t_" if (k < t_num) else "x_") +  (str(k + 1) if (k < t_num) else str(k+1-t_num))
    res_str += "(" + str(intersec[0]+1)
    for i in range(1, len(intersec)):
        res_str += "," + str(intersec[i]+1)
    res_str += ")"
    return res_str

def get_lst_str_set_of_full(func_lst):
    included = []
    included_in = []
    count = 1
    res_str = ""
    for i in range(len(func_lst)):
        for implicanta in func_lst[i]:
            if included.count(implicanta) == 0:
                included.append(implicanta)
                implicanta_str = str(count) + ". " + get_implicanta_str(implicanta) + " (" + str(i+1)
                count += 1
                tmp = [i]
                for j in range(i + 1, len(func_lst)):
                    if func_lst[j].count(implicanta) > 0:
                        implicanta_str += "," + str(j+1)
                        tmp.append(j)
                implicanta_str += ")"
                res_str += "   " + implicanta_str
                included_in.append(tmp)
    return included, included_in, res_str

def isPair(a, b):
    k = 0   #количество отличий
    n = -1  #номер бита отличия
    for i in range(len(a)):
        if (a[i] == 2 and b[i] != 2) or (a[i] != 2 and b[i] == 2): # если вектора не совпадают по форме
            return -1
        if a[i] != b[i]:
            k += 1
            n = i
    return (n if k == 1 else -1)

def sets_intersection(a, b):
    res = []
    for i in a:
        for j in b:
            if i == j:
                res.append(i)
    return res

def strike_str(text):
    return ''.join([u'\u0336{}'.format(c) for c in text])

def b_cover_a(a, a_inc, b, b_inc):
    if a_inc != b_inc:
        return False
    for i in range(len(a)):
        if a[i] != b[i] and b[i] != 2:
            return False
    return True

# за этот огрызок стыдно
def get_str_pairs(lst_full_set, lst_inc_in):
    lst = []
    lst_inc = list(lst_inc_in)  # в какие функции входит
    res_str = ""
    for implicanta in lst_full_set:
        tmp_lst = [(1 if k else 0) for k in implicanta]
        lst.append(tmp_lst)
    while(True):
        res_str = ""
        k = 0
        lst_tmp = []
        lst_inc_tmp = []
        for i in range(len(lst)-1):
            for j in range(i+1, len(lst)):
                intersec = sets_intersection(lst_inc[i], lst_inc[j])
                if len(intersec) > 0:
                    n = isPair(lst[i], lst[j])
                    index = ""
                    if n != -1: 
                        tmp = list(lst[i])
                        tmp[n] = 2
                        in_i = -1
                        in_i_t = -1
                        if tmp in lst:
                            in_i = lst.index(tmp)
                        if tmp in lst_tmp:
                            in_i_t = lst_tmp.index(tmp)
                        if (in_i == -1) or (in_i != -1 and lst_inc[in_i] != intersec):
                            if (in_i_t == -1) or (in_i_t != -1 and lst_inc_tmp[in_i_t] != intersec):
                                lst_tmp.append(tmp)
                                lst_inc_tmp.append(intersec)
                                k += 1
                                index = str(len(lst) + k)
                            else:
                                index = str(len(lst) + in_i_t + 1)
                        else:
                            index = str(in_i + 1)
                        implicanta_1_str = strike_str(get_implicanta_str_2(lst[i], lst_inc[i])) if b_cover_a(lst[i], lst_inc[i], tmp, intersec) else get_implicanta_str_2(lst[i], lst_inc[i])
                        implicanta_2_str = strike_str(get_implicanta_str_2(lst[j], lst_inc[j])) if b_cover_a(lst[j], lst_inc[j], tmp, intersec) else get_implicanta_str_2(lst[j], lst_inc[j])
                        res_str += "(" + str(i+1) + "-" + str(j+1) + "): " + implicanta_1_str + kon_char + implicanta_2_str + kon_char + get_implicanta_str_2(tmp, intersec) + " [" + index + "]\n"
        if (len(lst_tmp) == 0):
            break
        lst += lst_tmp
        lst_inc += lst_inc_tmp
    res_lst = []
    res_lst_inc = []
    for i in range(len(lst)):
        ok = True
        for j in range(len(lst)):
            if i != j and b_cover_a(lst[i], lst_inc[i], lst[j], lst_inc[j]):
                ok = False
                break
        if ok:      # если никакой терм не покрывает
            res_lst.append(lst[i])
            res_lst_inc.append(lst_inc[i])

    return res_lst, res_lst_inc, res_str


func_list = [parse_func(func) for func in Y]

lst_full_set, lst_inc_in, str_full_set = get_lst_str_set_of_full(func_list)
print(str_full_set)

simple_implicants_lst, simple_implicants_lst_inc, str_pairs = get_str_pairs(lst_full_set, lst_inc_in)
print(str_pairs)
simple_implicants_str = ""
k = 1
for i in range(len(simple_implicants_lst)):
    simple_implicants_str += str(k) + ". " + get_implicanta_str_2(simple_implicants_lst[i], simple_implicants_lst_inc[i]) + "    "
    k += 1
print(simple_implicants_str)