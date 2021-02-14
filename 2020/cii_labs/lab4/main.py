from tkinter import Tk, Button, Label, Entry, Frame
from widgets import PixelGrid, KeyValueList
from model import Model
import numpy as np
model = Model()


def train_command():
    model.train(int(e_tbox.get()), float(p_tbox.get()))


def test_command():
    class_label_list = ['/','-','*','+','%','root']
    result = model.test(
        np.array(
            grid.get_grid()
        )
    )
    result_list.clear_list();
    for i,j in zip(class_label_list,result):
        result_list.add_element(i,round(j,3))


root = Tk()

grid = PixelGrid(root, 7, 7)
recognize_button = Button(root, text='Распознать', command=test_command)

result_list = KeyValueList(root)

frame = Frame(root)
p_label = Label(frame, text='Норма обучения')
e_label = Label(frame, text='Кол-во эпох')

p_tbox = Entry(frame)
e_tbox = Entry(frame)

train_button = Button(frame, text='Обучить', command=train_command)

grid.grid(row=0, column=0, padx=20, pady=20)
recognize_button.grid(row=1, column=0, padx=20, pady=5)

result_list.grid(row=0, column=1, padx=20, pady=20)

frame.grid(row=0, column=2, padx=20, pady=20)

p_label.grid(row=0, column=0)
p_tbox.grid(row=0, column=1)
e_label.grid(row=1, column=0)
e_tbox.grid(row=1, column=1)
train_button.grid(row=2, column=0)

root.mainloop()
