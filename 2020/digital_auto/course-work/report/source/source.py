def automaton(t1,t2,x1,x2,x3):
    

    z1 = not t1 and t2
    z2 = not t2 and not x1
    z3 = not t2 and not x2

    u1 = x3 and z2
    u2 = t1 and z3
    u3 = not x3 and z1
    u4 = x3 and z1
    u5 = t1 and not t2
    u6 = not t1 and not t2

    v1 = u1 or u3
    v2 = u4 or u5
    f1 = u2 or u3
    f2 = u4 or u6
    y1 = u2 or u3
    y2 = v1 or v2
    y3 = u4 or u6

    return f1,f2,y1,y2,y3

trigger1 = False
trigger2 = False

#A1->A2 Z1 W3
input1,input2,input3 = True,False,False
trigger1,trigger2,output1,output2,output3 = automaton(trigger1,trigger2,input1,input2,input3)
print('Триггеры:',trigger1,trigger2,'Выходы:',output1,output2,output3)
#A2->A2 Z2 W4
input1,input2,input3 = False,False,True
trigger1,trigger2,output1,output2,output3 = automaton(trigger1,trigger2,input1,input2,input3)
print('Триггеры:',trigger1,trigger2,'Выходы:',output1,output2,output3)
#A2->A3 Z3 W5
input1,input2,input3 = False,False,False
trigger1,trigger2,output1,output2,output3 = automaton(trigger1,trigger2,input1,input2,input3)
print('Триггеры:',trigger1,trigger2,'Выходы:',output1,output2,output3)
#A3->A1 Z4 W2
input1,input2,input3 = False,True,False
trigger1,trigger2,output1,output2,output3 = automaton(trigger1,trigger2,input1,input2,input3)
print('Триггеры:',trigger1,trigger2,'Выходы:',output1,output2,output3)