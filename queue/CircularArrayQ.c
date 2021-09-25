#include <stdio.h>
#include <stdlib.h>
#include "CircularArrayQ.h"

CircularArrayQueue create_array_queue(){
    CircularArrayQueue caq;
    caq.front = -1;
    caq.rear = -1;
    return caq;
}

void init_array_queue(CircularArrayQueue *list){
    list->front = 0;
    list->rear = MAX - 1;
}

bool enqueue(CircularArrayQueue *list, Type p){
    if (is_full(*list) == false) {
        list->rear = (list->rear + 1) % MAX;
        list->data[list->rear] = p;
        return true;
    } else {
        return false;
    }
}

bool dequeue(CircularArrayQueue *list){
    if (is_empty(*list) == false) {
        list->front = (list->front + 1) % MAX;
        return true;
    } else {
        return false;
    }
}

bool is_empty(CircularArrayQueue list){
    return (list.rear + 1) % MAX == list.front ? true : false;
}

bool is_full(CircularArrayQueue list){
    return (list.rear + 2) % MAX == list.front ? true : false;
}

Type front(CircularArrayQueue list){
    return list.data[list.front];
}
