#Вариант 5.
#Разработать подсистему поиска совпадений между текстами. 
#Первая подпрограмм будет выполнять разбор и нормализацию текста. 
#Вторая выполнять сравнение в локальном хранилище.

import re
import numpy as np
def prepare_text(text):
    #разделители для продложений
    split_sentence = re.compile(r'[.|!|?|…]')
    #удаление предлогов
    remove_preposition = re.compile(r'и|или|без|около')
    text = text.lower()
    for char in ',-_:;':
        text.replace(char,' ')
    text = re.sub(remove_preposition,'',text.rstrip())
    splited_text = re.split(split_sentence,text) 
    return splited_text

def compare_text(splited_sample, splited_text):
    total_compare_count = len(splited_sample)+len(splited_text)
    compare_count = 0
    for text_str in splited_text:
        text_list = text_str.split(' ')
        for sample_str in splited_sample:
            sample_list = sample_str.split(' ')
            dict = text_list+sample_list
            text_vector = []
            sample_vector = []
            for i in range(len(dict)):
                if dict[i] in text_list:
                    text_vector.append(1)
                else:
                    text_vector.append(0)
            for i in range(len(dict)):
                if dict[i] in sample_list:
                    sample_vector.append(1)
                else:
                    sample_vector.append(0)
            result_vector=np.array(text_vector)+np.array(sample_vector)
            result_sum=result_vector.sum()
            if result_sum>len(dict)+1:
                compare_count=compare_count+1
    percent_of_similariry = compare_count/total_compare_count*100
    return percent_of_similariry


##print('Введите имя файла для проверки - ')
##text_file_name = input()
text_file_name = 'test.txt'

#print('Введите имя файла выборки - ')
#ctrl_file_name = input() 
ctrl_file_name = 'ctrl.txt'

text_file = open(text_file_name)
ctrl_file = open(ctrl_file_name)

text = text_file.read()
sample = ctrl_file.read()

splited_text = prepare_text(text)
splited_sample = prepare_text(sample)

percent = compare_text(splited_sample,splited_text)
print(percent,'%')

