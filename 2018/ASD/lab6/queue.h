#ifndef QUEUE_H_
#define QUEUE_H_
#include "list.h"
    extern const char queue_ok;
    extern const char queue_under;
    extern const char queue_over;
    extern const char queue_mem_error;
    char queue_error; // Переменная ошибок

    typedef list queue;
    queue* queue_init(unsigned size); // Инициализация очереди
    void queue_put(queue *q, base_type e); // Поместить элемент в очередь
    base_type queue_get(queue *q); // Извлечь элемент из очереди
    base_type queue_read(queue *q);  // Прочитать элемент
    void queue_print(queue *q);
    void queue_done(queue *q); //Деструктор
    //Предикаты
    int queue_empty(queue *q);
    int queue_full(queue *q);
#endif
