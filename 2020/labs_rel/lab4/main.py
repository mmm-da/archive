import numpy 
import cProfile
from tqdm import tqdm
delta_t = 0.001

class Channel:
    def __init__(self):
        self.work_timer = 0
        self.state = True
    
    def is_empty(self):
        return self.state
    
    def set_work(self,work_time):
        if self.state:
            self.state = False
            self.work_timer = work_time
    
    def step(self):
        if not self.state and self.work_timer:
            self.work_timer -= delta_t
            if self.work_timer < delta_t:
                self.state = True
                self.work_timer = 0

class Network:
    def __init__(self,ch_count,intensivity,avr_compute_time):
        self.intensivity = intensivity
        self.avr_compute_time = avr_compute_time
        self.rnd_gen = numpy.random.default_rng()
        self.next_msg = round(self.rnd_gen.poisson(self.intensivity),3)
        self.total_time = 0
        self.total_task = 0
        self.miss_task = 0
        self.channels = [] 
        self.task_times = []
        self.empty_channels = []
        for i in range(0,ch_count):
            self.channels.append(Channel())

### Возвращает номер свободного канала, если все каналы заняты возвращает -1
    def check_free_channel(self):
        for index,i in enumerate(self.channels):
            if i.is_empty():
                return index 
        return -1

    def empty_channels_count(self):
        state_count = 0
        for i in self.channels:
            state_count += int(i.is_empty())
        return state_count

    def step(self):
        if self.next_msg < delta_t:
            self.new_task()
        else:
            self.next_msg -= delta_t

        for i in self.channels:
            i.step()

        self.total_time += delta_t

        self.empty_channels.append(self.empty_channels_count())

    def new_task(self):
        self.next_msg = round(self.rnd_gen.poisson(self.intensivity),3)
        free_channel = self.check_free_channel()
        if not (free_channel == -1):
            self.total_task +=1
            task_time = round(self.rnd_gen.normal(self.avr_compute_time,0.1),3)
            self.task_times.append(task_time)
            self.channels[free_channel].set_work(task_time)
        else:
            self.miss_task += 1

    def get_avr_task_time(self):
        return numpy.mean(self.task_times)
    
    def get_avr_empty_chanells(self):
        return numpy.mean(self.empty_channels)

net = Network(4,5/4,0.5)
for i in range(0,1000*60):
    net.step()

