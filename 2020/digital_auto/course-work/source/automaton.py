import numpy as np
from pprint import pprint
from math import ceil
from pydot import Dot, Edge, Node
from graphviz import Digraph
import dot2tex
import matplotlib.pyplot as plt
from sortedcontainers import SortedSet

SUB = str.maketrans("0123456789", "₀₁₂₃₄₅₆₇₈₉")

def get_bin(x, n=0):
    return format(x, 'b').zfill(n)

def set_to_codes(input_set):
    result = {}
    code_count = 2**ceil(np.log2(len(input_set)))
    code_len = ceil(np.log2(len(input_set)))
    codes_arr = []
    for i in range(0,code_count):
        code = get_bin(i,code_len)
        codes_arr.append(code) 
    for index,item in enumerate(input_set):
        result[item] = Code(str(item),codes_arr[index])
    return result

class Code:
    def __init__(self,val,code):
        self.value = val
        self.code = code
        self.list = []
        for i in code:
            if i == '-':
                self.list.append('-')
            else:
                self.list.append(bool(int(i)))

    def latex_str(self,prefix):
        result = r''
        for index,i in enumerate(self.code,start = 1):
            if i == '-':
                continue
            if not bool(int(i)):
                result += '\\overline '
            result += prefix+'_'+str(index)+' '
        return result
    
    def pretty_str(self,prefix):
        result = ''
        for index,i in enumerate(self.code,start = 1):
            if i == '-':
                continue
            if not bool(int(i)):
                result += '!'
            result += prefix+str(index).translate(SUB)
        return result
    
    def impl_str(self,prefix):
        result = ''
        for index,i in enumerate(self.code,start = 1):
            if i == '-':
                continue
            if not bool(int(i)):
                result += '!'
            result += prefix+str(index)
        return result

    def lf_str(self,prefix):
        result = ''
        for index,i in enumerate(self.code,start = 1):
            if i == '-':
                continue
            result += prefix+str(index)
            if not bool(int(i)):
                result += '\''
            result += ' '
        return result

    def __iter__(self):
        return iter(self.list)

    def __str__(self):
        return self.code

    def __len__(self):
        return len(self.list)

class Automaton:
    def __init__(self, transition_matrix):
        super().__init__()

        self._transition_matrix = np.array(transition_matrix)

        self._state_set = SortedSet()
        self._input_set = SortedSet()
        self._output_set = SortedSet()

        self.state_codes = None
        self.input_codes = None
        self.output_codes = None

        self.state_prefix = "a"
        self.input_prefix = "z"
        self.output_prefix = "w"

        input_no = 1
        for transition_str in self._transition_matrix:
            self._input_set.add(input_no)
            input_no += 1
            for state in transition_str:
                if state != '-':
                    self._state_set.add(str(state))

    def get_state_code(self):
        if self.state_codes == None:
            self.state_codes = set_to_codes(self._state_set)
        return self.state_codes

    def get_input_code(self):
        if self.input_codes == None:
            self.input_codes = set_to_codes(self._input_set)
        return self.input_codes

    def get_output_code(self):
        if self.output_codes == None:
            self.output_codes = set_to_codes(self._output_set)
        return self.output_codes
    
    def get_D_trigger_func(self,format = 'latex'):
        result = []
        input_codes = self.get_input_code()
        output_codes = self.get_output_code()
        state_codes = self.get_state_code()
        
        input_code_len = len(input_codes[1].list)
        state_code_len = len(state_codes['1'].list)

        for trigger_func in range(0,state_code_len):
            func = ''
            for input_index,input_str in enumerate(self._transition_matrix,start=1):
                for current_state_index,next_state in enumerate(input_str,start=1):
                    if next_state == '-':
                        continue
                    if state_codes[str(next_state)].list[trigger_func]:
                        if format == 'latex':
                            func += r'({}{})\lor '.format(state_codes[str(current_state_index)].latex_str('t'),input_codes[input_index].latex_str('x'))
                        elif format == 'impl':
                            func += r'{}{} ∨ '.format(state_codes[str(current_state_index)].impl_str('t'),input_codes[input_index].impl_str('x'))
                        elif format == 'lf':
                            func += r'{}{} + '.format(state_codes[str(current_state_index)].lf_str('t'),input_codes[input_index].lf_str('x'))
                        else:
                            func += '({}{})∨'.format(state_codes[str(current_state_index)].pretty_str('t'),input_codes[input_index].pretty_str('x'))
            if format=='latex':
                result.append(func[:-5])
            else:
                result.append(func[:-1])
        return result

    def get_T_trigger_func(self,format = 'latex'):
        result = []
        input_codes = self.get_input_code()
        output_codes = self.get_output_code()
        state_codes = self.get_state_code()
        
        input_code_len = len(input_codes[1].list)
        state_code_len = len(state_codes['1'].list)

        for trigger_func in range(0,state_code_len):
            func = ''
            for input_index,input_str in enumerate(self._transition_matrix,start=1):
                for current_state_index,next_state in enumerate(input_str,start=1):
                    if next_state == '-':
                        continue
                    if state_codes[str(next_state)].list[trigger_func] ^ state_codes[str(current_state_index)].list[trigger_func]:
                        if format == 'latex':
                            func += r'({}{})\lor '.format(state_codes[str(current_state_index)].latex_str('t'),input_codes[input_index].latex_str('x'))
                        elif format == 'lf':
                            func += r'{}{} + '.format(state_codes[str(current_state_index)].lf_str('t'),input_codes[input_index].lf_str('x'))
                        elif format == 'impl':
                            func += r'{}{} ∨ '.format(state_codes[str(current_state_index)].impl_str('t'),input_codes[input_index].impl_str('x'))
                        else:
                            func += '({}{})∨'.format(state_codes[str(current_state_index)].pretty_str('t'),input_codes[input_index].pretty_str('x'))
            if format=='latex':
                result.append(func[:-5])
            else:
                result.append(func[:-1])
        return result
    
    def get_RS_trigger_func(self,format = 'latex'):
        R_result = []
        S_result = []
        input_codes = self.get_input_code()
        output_codes = self.get_output_code()
        state_codes = self.get_state_code()
        
        input_code_len = len(input_codes[1].list)
        state_code_len = len(state_codes['1'].list)

        for trigger_func in range(0,state_code_len):
            R_func = ''
            S_func = ''
            for input_index,input_str in enumerate(self._transition_matrix,start=1):
                for current_state_index,next_state in enumerate(input_str,start=1):
                    if next_state == '-':
                        continue
                    if state_codes[str(next_state)].list[trigger_func]:
                        if format == 'latex':
                            R_func += r'({}{})\lor '.format(state_codes[str(current_state_index)].latex_str('t'),input_codes[input_index].latex_str('x'))
                        else:
                            R_func += '({}{})∨'.format(state_codes[str(current_state_index)].pretty_str('t'),input_codes[input_index].pretty_str('x'))
                    else:
                        if format == 'latex':
                            S_func += r'({}{})\lor '.format(state_codes[str(current_state_index)].latex_str('t'),input_codes[input_index].latex_str('x'))
                        else:
                            S_func += '({}{})∨'.format(state_codes[str(current_state_index)].pretty_str('t'),input_codes[input_index].pretty_str('x'))
            if format=='latex':
                R_result.append(R_func[:-5])
                S_result.append(S_func[:-5])
            else:
                R_result.append(R_func[:-1])
                S_result.append(S_func[:-1])

        return R_result,S_result

class MooreAutomaton(Automaton):
    def __init__(self, transition_matrix, output_str):
        Automaton.__init__(self, transition_matrix)
        self._output_str = output_str

        for output in self._output_str:
            self._output_set.add(output)

        if len(self._output_str) != len(self._state_set):
            raise ValueError("Проверьте выводы Мура.")

        print("Алфавит входов: ")
        pprint(self._input_set)
        print("Алфавит выходов:")
        pprint(self._output_set)
        print("Алфавит состояний:")
        pprint(self._state_set)

    def plot_graph(self):

        graph = Digraph(comment="Автомат Мура")

        # добавляем вершины графа - состояния
        for output_signal, state in enumerate(self._state_set,start=1):
            graph.node(
                str(state),
                label=self.state_prefix
                + str(state)
                + " ({})".format(self.get_output_code()[output_signal].pretty_str('y')
                ),
            )

        # добавляем ветви графа - элементы матрицы переходов
        for index, state in enumerate(self._state_set):
            for input_signal, next_state in enumerate(self._transition_matrix.T[index],start =1):
                if next_state == '-':
                    continue
                graph.edge(
                    str(state),
                    str(next_state),
                    label=self.get_input_code()[input_signal].pretty_str('x'),
                )


        graph.save("moore_graph.dot")
        return graph

    def get_output_func(self,format = 'latex'):
        result = []
        input_codes = self.get_input_code()
        output_codes = self.get_output_code()
        state_codes = self.get_state_code()
        
        output_code_len = len(output_codes[1].list)

        for output_func in range(0,output_code_len):
            func = ''
            for output_index in output_codes:
                if output_codes[output_index].list[output_func]:
                    #просмотр строки выходов
                    for state_index,output in enumerate(self._output_str,start=1):
                        if format == 'latex':
                            func += '({})\lor '.format(state_codes[str(state_index)].latex_str('t'))
                        elif format == 'lf':
                            func += '{} + '.format(state_codes[str(state_index)].lf_str('t'))
                        elif format == 'impl':
                            func += '{} ∨ '.format(state_codes[str(state_index)].impl_str('t'))
                        else:
                            func += '({})∨'.format(state_codes[str(state_index)].pretty_str('t'))
            if format=='latex':
                result.append(func[:-5])
            else:
                result.append(func[:-1])
        return result


class MillyAutomaton(Automaton):
    def __init__(self, transition_matrix, output_matrix):
        Automaton.__init__(self, transition_matrix)
        self._output_matrix = output_matrix

        for input_str in self._output_matrix:
            for output in input_str:
                if output != '-':
                    self._output_set.add(str(output))

        print("Алфавит входов: ")
        pprint(self._input_set)
        print("Алфавит выходов:")
        pprint(self._output_set)
        print("Алфавит состояний:")
        pprint(self._state_set)

    def plot_graph(self):
        graph = Digraph(comment="Автомат Милли")

        # добавляем вершины графа - состояния
        for state in self._state_set:
            graph.node(str(state),label = self.state_prefix + str(state).translate(SUB))

        # добавляем ветви графа - элементы матрицы переходов
        for input_index,input_str in enumerate(self._transition_matrix):
            for state_index,next_state in enumerate(input_str):
                if next_state == '-':
                    continue
                graph.edge(
                    str(list(self._state_set)[state_index]),
                    str(next_state),
                    label=self.input_codes[input_index+1].pretty_str('x') + '\n (' + self.output_codes[self._output_matrix[input_index][state_index]].pretty_str('y') +')'
                )

        graph.save("milly_graph.dot")
        return graph

    def get_output_func(self,format = 'latex'):
        result = []
        input_codes = self.get_input_code()
        output_codes = self.get_output_code()
        state_codes = self.get_state_code()
        
        output_code_len = len(output_codes[1].list)

        for output_func in range(0,output_code_len):
            func = ''
            for output_index in output_codes:
                if output_codes[output_index].list[output_func] == '-':
                    continue
                if output_codes[output_index].list[output_func]:
                    #просмотр таблицы выходов
                    for input_index,input_str in enumerate(self._output_matrix,start=1):
                        for state_index,output in enumerate(input_str,start=1):
                            if output == '-':
                                continue
                            if output == output_codes[output_index].value:
                                if format == 'latex':
                                    func += '({} {})\lor '.format(state_codes[str(state_index)].latex_str('t'),input_codes[input_index].latex_str('x'))
                                elif format == 'lf':
                                    func += '{}{} + '.format(state_codes[str(state_index)].lf_str('t'),input_codes[input_index].lf_str('x'))
                                elif format == 'impl':
                                    func += '{}{} ∨ '.format(state_codes[str(state_index)].impl_str('t'),input_codes[input_index].impl_str('x'))
                                else:
                                    func += '({}{})∨'.format(state_codes[str(state_index)].pretty_str('t'),input_codes[input_index].pretty_str('x'))
            if format=='latex':
                result.append(func[:-5])
            else:
                result.append(func[:-1])
        return result

