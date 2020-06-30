# -*- coding: utf-8 -*-

import itertools


def print_table(t):
    ind = 0
    for x in map(''.join, itertools.product('01', repeat=var_count)):
        print(
            '| ' + x + '|' + str(int(t[ind])).rjust(2) + ' |'
        )
        ind += 1


# Количество переменных
var_count = 5


# Исправная функция (смоделирована комбинационная схема)
def good_schema(vars):
    x1 = bool(int(vars[0]))
    x2 = bool(int(vars[1]))
    x3 = bool(int(vars[2]))
    x4 = bool(int(vars[3]))
    x5 = bool(int(vars[4]))

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


# Функция с неисправностью, fault_gate - вход,
# на котором наблюдается неисправность,
# fault_val - значение на этом входе
def bad_schema(vars, fault_gate, fault_val):
    x1 = fault_val if fault_gate == 'x1' else bool(int(vars[0]))
    x2 = fault_val if fault_gate == 'x2' else bool(int(vars[1]))
    x3 = fault_val if fault_gate == 'x3' else bool(int(vars[2]))
    x4 = fault_val if fault_gate == 'x4' else bool(int(vars[3]))
    x5 = fault_val if fault_gate == 'x5' else bool(int(vars[4]))
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

# Входы, на которых наблюдается неисправность
# f_inputs = ['x1', 'x2', 'x3', 'x4', 'nx1', 'nx2', 'nx3', 'nx4', 'z1', 'z2', 'u1', 'u2', 'u3', 'u4', 'v1', 'v2']
f_inputs = ['x1', 'x2', 'x3', 'x4', 'x5']

# Набор значений исходной функции
f_good = []
for x in map(''.join, itertools.product('01', repeat=var_count)):
    f_good.append(good_schema(x))

print("Исходная таблица истинности:")
print_table(f_good)

# Необнаружимые
undetectable = 0
# Неразличимые
undiagnosable = 0

# F_G - множество всех функций неисправностей
F_G = []
# Подозреваемые неисправности
suspected = []
last_suspected = 0

# Проверим результат работы на всех возможных неисправностях
for inp in f_inputs:
    for val in (0, 1):
        f_test = []
        for x in map(''.join, itertools.product('01', repeat=var_count)):
            f_test.append(bad_schema(x, inp, val))
        # Отсеем повторяющиеся результаты (т.е., неразличимые неисправности) и необнаружимые неисправности
        if f_test in F_G:
            undiagnosable += 1
            # Дописываем неисправность к такой же строке
            index = F_G.index(f_test)
            suspected[index].append(inp + "({})".format(val))
        elif f_test == f_good:
            undetectable += 1
        else:
            F_G.append(f_test)
            # Неисправность будет соответствовать своей строке
            suspected.append([inp+"({})".format(val)])
            last_suspected += 1


# Вывод таблиц истинности функций, реализующих неисправности
i = 1
print_1 = True
if print_1:
    for func in F_G:
        print("Таблица истинности функции f{}, реализующей неисправность {}".format(i, suspected[i-1]))
        i += 1
        print_table(func)

print("Обнаружено {} необнаружимых и {} неразличимых неисправностей".format(undetectable, 2 * undiagnosable))

# Теперь нужно составить матрицу функций неисправности. Столбцы - это наборы входных сигналов, строки - значения
# функций на этих наборах

# Инициализация
D = []
for i in range(len(F_G) + var_count):
    D.append([])
# Заполнение матрицы
X_lst = list(itertools.product('01', repeat=var_count))
for j in range(2**var_count):
    for i in range(var_count):
        D[i].append(int(X_lst[j][i]))
    for i in range(len(F_G)):
        D[i+var_count].append(int(F_G[i][j]))

# Вывод получившейся матрицы
print("Матрица функций неисправностей")
print("    ", end='')
for i in range(len(D[0])):
    print("X{:<2}".format(i+1), end = ' ')
print()
count = 0
for row in D:
    if count < var_count:
        print("x{:<2}".format(count+1), end=' ')
    else:
        print("f{:<2}".format(count+1-var_count), end=' ')
    for x in row:
        print(x, end='   ')
    if (count >= var_count):
        print(','.join(suspected[count-var_count]))
    else:
        print()
    count += 1

# Разностные функции
R = []
for i in range(var_count, len(D)):
    R.append([])
    for j in range(len(D[i])):
        # Говоря в терминах булевых значений, xor и != - одно и то же
        R[i - var_count].append(D[i][j] != f_good[j])

# Вывод получившейся матрицы
print("Матрица разностных функций")
print("    ", end='')
for i in range(len(R[0])):
    print("X{:<2}".format(i+1), end = ' ')
print()
count = 0
print("f  ", '   '.join(map(str, map(int, f_good))))
for row in R:
    print("R{:<2}".format(count+1), end=' ')
    for x in row:
        print(int(x), end='   ')
    print(','.join(suspected[count]))
    count += 1


# Функция, которая проверяет комбинационную схему, представленную функцией func
def check_function(func, *args):
    # Диагностический тест, будут использоваться наборы 1, 15, 13, 15, 27
    test_set = X_lst
    # Неисправности
    errors_set = suspected
    # Дерево тестов можно записать в следующем виде:
    #                  X10
    #              X8           X31
    #           F2   X2      X24   X5
    #          _ _ F6  F8  X11 F3 F9 X7
    #             _  _ _  F7 F1 _ _ _ _ F4  F5
    #                    _ _ _ _       _  _ _ _
    # Индекс элемента получаем как 2*индекс текущего эл-та+1 + результат, полученный на данном наборе
    # Например, если на наборе X5 (индекс 0) получили рез-т 1, то переходим к индексу 2*0+1+1 = 2, т.е., X15
    test_tree = ("X10"
            ,"X8", "X31",
        "F2", "X2", "X24", "X5"
    ,"", "", "F6", "F8", "X11", "F3", "F9", "X7",
"", "", "", "", "F7", "F1","","","","", "F4", "F5",
                "","","","",          "","","","")
    index = 0
    while True:
        node = test_tree[index]
        if node[0] == "X":
            r = func(test_set[
                         int(node[1:]) - 1
                     ], *args)
            print("Проверили схему на наборе {}, получили результат {}".format(node, int(r)))
            index = 2 * index + 1 + int(r)
        elif node == "F":
            print("Схема исправна, либо неисправность является необнаружимой")
            break
        elif node[0] == "F":
            print("Заключение: в схеме имеется неисправность на входе {}".format(errors_set[
                                                                            int(node[1:])-1
                                                                        ][0]))
            break
        else:
            print("Ошибка в алгоритме поиска неисправностей")
            break


for inp in f_inputs:
    for val in (0, 1):
        print("Внесли неисправность {}({})".format(inp, val))
        check_function(bad_schema, inp, val)
        print()
        