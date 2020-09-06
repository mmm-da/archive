import numpy
import matplotlib.pyplot as plt
from material import import_materials_json 

material_dict = import_materials_json('./materials.json')

class Block:
    def __init__(self,energy = 0,m = None,st = 0,flag = False):
        #Блок обьемом 1 м3.
        #Внутреняя энергия блока.
        #Температура = кол-во энергии / теплоемкость вещества
        self._current_energy = energy
        #Материал
        self._material = m
        #Агрегатное состояние
        #0 - твердое тело (тепловое излучение и теплообмен)
        #1 - жидкое тело (конвекция, теплообмен, излучение)
        #2 - газ (конвекция, теплообмен)
        self._state = st
        #Флаг константного блока - запрещает изменение состояния блока и его перемещение (вечный статичный нагреватель\охладитель)
        self._const_flag = flag

    def __str__(self):
        if self._state == 0:
            state_str = 'Твердое тело'
        elif self._state == 1:
            state_str = 'Жидкое тело'
        else:
            state_str = 'Газ'
        return str(self._current_energy)
        #return ("Внутренняя энергия: "+str(self._current_energy)+'. Агрегатное состояние: '+state_str+'. Материал: '+self._material.name+'\n')
    
    @property
    def current_energy(self):
        return self._current_energy
    @current_energy.setter
    def current_energy(self,value):
        self._current_energy = value
    
    @property
    def const_flag(self):
        return self._const_flag
    @const_flag.setter
    def const_flag(self,value):
        self._const_flag = value

    @property
    def state(self):
        return self._state
    
    @property
    def material(self):
        return self._material
    @material.setter
    def material(self,value):
        self._material = value
    
def map_2d(heigth,width):
    result_list = []
    for i in range(0,heigth):
        temp_list = []
        for j in range(0,width):
            temp_list.append(Block(1000,material_dict["Камень"],0,False))
        result_list.append(temp_list)
    return result_list

def map_3d(heigth,width,depth):
    result_list = []
    for i in range(0,heigth):
        temp_list = []
        for j in range(0,width):
            temp_temp_list = []
            for z in range(0,depth):
                temp_temp_list.append(Block(1000,material_dict["Камень"],0,False))
            temp_list.append(temp_temp_list)
        result_list.append(temp_list)
    return result_list

def thermal_swap(block1,block2):
    temperature1 = block1.current_energy/block1.material.thermal_capacity
    temperature2 = block2.current_energy/block2.material.thermal_capacity
    #True: 1->2, False: 1<-2
    swap_direction = temperature1>temperature2
    if swap_direction:
        temperature_diff = temperature1-temperature2
    else:
        temperature_diff = temperature2-temperature1
    swap_k = min(block1.material.thermal_conductivity,block2.material.thermal_conductivity)
    swap_value = swap_k * temperature_diff
    if swap_direction:
        if not (block1.const_flag):
            block1.current_energy = block1.current_energy - swap_value   
        if not (block2.const_flag):
            block2.current_energy = block2.current_energy + swap_value   
    else:
        if not (block1.const_flag):
            block1.current_energy = block1.current_energy + swap_value   
        if not (block2.const_flag):
            block2.current_energy = block2.current_energy - swap_value   
    return (block1,block2)

def procedure_map(map_any):
    return numpy.array(map_any)

def neighbors_2d(x,y,size_x,size_y):
    neighbors_list = []
    neighbors_list.append([x-1,y])

    if not ((y-1)<0):
        neighbors_list.append([x,y-1])
    
    if not ((y+1)>=size_y):
        neighbors_list.append([x,y+1])
    
    if((x+1)>=size_x):
        neighbors_list.append([0,y])
    else:
        neighbors_list.append([x+1,y])
    
    return neighbors_list


def thermal_cycle_2d(map_2d):
    new_map = numpy.array(map_2d)
    for j in range(0,len(new_map)):
        for i in range(0,len(new_map[j])):
            neighbors_list = neighbors_2d(i,j,len(new_map[i]),len(new_map)) 
            print(neighbors_list,i,j)
            for k in neighbors_list:
                new_map[i][j],new_map[k[0]][k[1]] = thermal_swap(map_2d[i][j],map_2d[k[0]][k[1]])
    return new_map

map = map_3d(10,10,10)
p_map = procedure_map(map)

for i in range(0,len(p_map)):
    for j in range(0,len(p_map[0][0])):
        p_map[i][0][j].material = material_dict["Сущность"]
        p_map[1][1][j].material = material_dict["Сущность"]
        p_map[i][2][j].material = material_dict["Сущность"]
        p_map[i][3][j].material = material_dict["Сущность"]
        p_map[i][8][j].material = material_dict["Металл"]

p_map[1,0,1].current_energy = 90
for j in p_map:
    for k in j:
        for c in k:
            print(c.current_energy,end =" ")
        print()
    print()
print()
    