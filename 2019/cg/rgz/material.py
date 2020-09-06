import json 

class Material:
    def __init__(self):
        #название - строка с наименованием материала.
        self._name = 'Имя'
        #плотность - кг на кубический метр.
        self._density = 1
        #теплоемкость - количество энергии требуемой для изменения температуры в К на 1 градус
        self._thermal_capacity = 1
        #теплопроводность - количество энергии передаваемое при теплообмене при разности температур в 1 K.
        self._thermal_conductivity = 1
    
    def __hash__(self):
        return hash(self._name)
    
    def __str__(self):
        s = ''
        s = (s + self._name + '. Плотность: ' + str(self._density) + ' кг/м3. Теплоемкость: ' + str(self._thermal_capacity) + '. Теплопроводность: ' + str(self._thermal_conductivity))
        return s

    @property
    def name(self):
        return self._name
    @name.setter
    def name(self,value):
        self._name = value 

    @property
    def density(self):
        return self._density
    @density.setter
    def density(self,value):
        self._density = value 

    @property
    def thermal_capacity(self):
        return self._thermal_capacity
    @thermal_capacity.setter
    def thermal_capacity(self,value):
        self._thermal_capacity = value 

    @property
    def thermal_conductivity(self):
        return self._thermal_conductivity
    @thermal_conductivity.setter
    def thermal_conductivity(self,value):
        self._thermal_conductivity = value 
    
    @property
    def color_red(self):
        return self._color_red

    @property
    def color_green(self):
        return self._color_green

    @property
    def color_blue(self):
        return self._color_blue

    @property
    def color_alpha(self):
        return self._color_alpha

    @property
    def textureName(self):
        return self._texture_name

    def from_json(self,json_dict):
        self._name = json_dict['name']
        self._density = json_dict['density']
        self._thermal_capacity = json_dict['thermal_capacity']
        self._thermal_conductivity = json_dict['thermal_conductivity']
        self._color_red = json_dict['color_red']
        self._color_green = json_dict['color_green']
        self._color_blue = json_dict['color_blue']
        self._color_alpha = json_dict['color_alpha']
        self._texture_name = json_dict['texture_name']

def import_materials_json(filepath):
    result = {}
    with open(filepath,'r', encoding="utf-8") as file:
        json_data = json.load(file)
    for i in json_data:
        temp = Material()
        temp.from_json(i)
        result[temp.name] = temp
    return result

