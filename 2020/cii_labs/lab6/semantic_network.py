import graphviz 
import re 

def plot_network(filepath):
    nodes = []
    graph = graphviz.Digraph('neato')
    graph.attr(overlap='scale')
    pattern = r'(part_of|a_is_b)\((".*"),(".*")\).'
    pattern = re.compile(pattern)
    with open(filepath) as file:
        for line in file:
            result = pattern.match(line)
            if result:
                command = result.group(1)
                a = result.group(2)
                b = result.group(3)
                if a not in nodes:
                    nodes.append(a)
                    graph.node(a)
                if b not in nodes:
                    nodes.append(b)
                    graph.node(b)
                if command == 'a_is_b':
                    graph.edge(a,b)
                else:
                    graph.edge(b,a)
    return graph

plot_network('./task1.pro').render('./graph.dot')