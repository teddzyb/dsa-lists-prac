#include <stdio.h>
#include <stdlib.h>
#include "Exercise1.h"

int get_queue_length(CircularArrayQueue list){
    return list.rear > list.front ? (list.rear - list.front) + 1 : MAX + 1 - (list.front - list.rear);
}

PersonLinkedList get_all_females(CircularArrayQueue list){
    PersonLinkedList femaleList = NULL, tempNode;
    Person tempPerson;
    Position tempPos = list.rear;
    while (list.front != tempPos) {
        tempPerson = front(list);
        if (tempPerson.sex == 'F' || tempPerson.sex == 'f') {
            tempNode = (PersonLinkedList) malloc(sizeof(PersonNode));
            if (tempNode != NULL) {
                tempNode->elem = tempPerson;
                tempNode->next = femaleList;
                femaleList = tempNode;
            }
        }
        dequeue(&list);
        enqueue(&list, tempPerson);
    }
    return femaleList;
}

PersonDynamicArrayList remove_all_males(CircularArrayQueue *list){
    Person tempPerson;
    int i = 0, temp = list->rear;
    PersonDynamicArrayList maleList;
    init_DAL(&maleList);
    while ((list->front - 1) % MAX != temp) {
        tempPerson = list->data[list->front];
        if (tempPerson.sex == 'M' || tempPerson.sex == 'm') {
            maleList.data[i] = tempPerson;
            i++;
        } else {
            list->rear = (list->rear + 1) % MAX;
            list->data[list->rear] = tempPerson;
        }
        list->front = (list->front + 1) % MAX;
    }
    return maleList;
}
