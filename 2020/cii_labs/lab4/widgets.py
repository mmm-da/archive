from tkinter import Button, Frame, Listbox


class PixelGridButton(Button):
    def __init__(self, master=None):
        Button.__init__(self, master, command=self.click_button, bg='white', height=1, width=2)
        self.master = master
        self.state = False

    def click_button(self):
        self.state = not self.state
        if self.state:
            Button.configure(self, bg='black')
        else:
            Button.configure(self, bg='white')

    def get_state(self):
        return self.state

    def set_state(self, state):
        self.state = state
        if self.state:
            Button.configure(self, bg='black')
        else:
            Button.configure(self, bg='white')


class PixelGrid(Frame):
    def __init__(self, master, x_size, y_size):
        Frame.__init__(self, master)
        self.buttons = []
        for i in range(y_size):
            row = []
            for j in range(x_size):
                row.append(
                    PixelGridButton(self)
                )
            self.buttons.append(row)
        for i, row in enumerate(self.buttons):
            for j, button in enumerate(row):
                button.grid(row=i, column=j)

    def get_grid(self):
        grid = []
        for row in self.buttons:
            for button in row:
                grid.append(
                    1 if button.get_state() else 0
                )
        print(grid)
        return grid

    def set_grid(self, grid):
        for i, row in enumerate(self.buttons):
            for j, button in enumerate(row):
                button.set_state(bool(grid[i][j]))


class KeyValueList(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.list = Listbox(self)
        self.list.pack()

    def clear_list(self):
        self.list.delete(0, 'end')

    def add_element(self, key, value):
        self.list.insert('end', '{}: {}'.format(key, value))

