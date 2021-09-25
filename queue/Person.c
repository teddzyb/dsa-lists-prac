#include <stdio.h>
#include <string.h>
#include "Person.h"

Person createPerson(String name, char sex, String city) {
    Person p;

    strcpy(p.name, name);
    p.sex = sex;
    strcpy(p.city, city);

    return p;
}

void displayPersonInfo(Person p) {
    printf("{%s | %c | %s}\n", p.name, p.sex, p.city);
}


/* Static Array List */

void init_SAL(PersonStaticArrayList *list){
    list->count = 0;
}

void insert_first_SAL(PersonStaticArrayList *list, Person p){
    int i;
    if (list->count != MAX_LIST) {
        for (i = list->count; i > 0; i--) {
            list->data[i] = list->data[i - 1];
        }
        list->data[0] = p;
        list->count++;
    }
}

void insert_last_SAL(PersonStaticArrayList *list, Person p){
    if (list->count != MAX_LIST) {
        list->data[list->count] = p;
        list->count++;
    }
}

void insert_at_SAL(PersonStaticArrayList *list, Person p, int index){
    int i;
    if (list->count != MAX_LIST) {
        for (i = list->count; i != index; i--) {
            list->data[i] = list->data[i - 1];
        }
        list->data[i] = p;
        list->count++;
    }
}

void delete_first_SAL(PersonStaticArrayList *list){
    int i;
    for (i = 0; i < list->count - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->count--;
}

void delete_last_SAL(PersonStaticArrayList *list){
    list->count--;
}

void delete_by_sex_SAL(PersonStaticArrayList *list, char sex){ // all ocurrences
    int i, j;
    for (i = 0; i < list->count; i++) {
        if (list->data[i].sex == sex) {
            for (j = i; j < list->count - 1; j++) {
                list->data[j] = list->data[j + 1];
            }
            i--;
            list->count--;
        }
    }
}

void display_SAL(PersonStaticArrayList list){
    int i;
    for (i = 0; i < list.count; i++) {
        displayPersonInfo(list.data[i]);
    }
}


/* Dynamic Array List - v1 
 * Doubles the maximum size of the array when full.
 */

void init_DAL(PersonDynamicArrayList *list){
    list->count = 0;
    list->max = 1;
    list->data = (Person *) malloc(sizeof(Person));
}

void insert_first_DAL(PersonDynamicArrayList *list, Person p){
    int i;
    if (list->count == list->max) {
        list->data = realloc(list->data, sizeof(Person) * (list->count * 2));
        list->max *= 2;
    }
    
    for (i = list->count; i > 0; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[0] = p;
    list->count++;
}

void insert_last_DAL(PersonDynamicArrayList *list, Person p){
    if (list->count == list->max) {
        list->data = realloc(list->data, sizeof(Person) * (list->count * 2));
        list->max *= 2;
    }

    list->data[list->count] = p;
    list->count++;
}

void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index){
    int i;
    if (list->count == list->max) {
        list->data = realloc(list->data, sizeof(Person) * (list->count * 2));
        list->max *= 2;
    }

    for (i = list->count; i != index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[i] = p;
    list->count++;
}

void delete_first_DAL(PersonDynamicArrayList *list){
    int i;
    for (i = 0; i < list->count - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->count--;
}

void delete_last_DAL(PersonDynamicArrayList *list){
    list->count--;
}

void delete_by_city_DAL(PersonDynamicArrayList *list, String city){ // first ocurrence
    int i, j;
    for (i = 0; i < list->count && strcmp(list->data[i].city, city) != 0; i++) {}
    if (i != list->count) {
        for (j = i; j < list->count - 1; j++) {
            list->data[j] = list->data[j+1];
        }
        list->count--;
    }
}

void display_DAL(PersonDynamicArrayList list){
    int i;
    for (i = 0; i < list.count; i++) {
        displayPersonInfo(list.data[i]);
    }
}


/* Dynamic Array List - v2 
 * Doubles the maximum size of the array when full.
 * The Dynamic Array List must also be created in the heap.
 */

void init_DAL_2(PersonDynamicArrayList **list){
    (*list)->count = 0;
    (*list)->max = 1;
    (*list)->data = (Person *) malloc(sizeof(Person));
}

void insert_first_DAL_2(PersonDynamicArrayList *list, Person p){
    int i;
    if (list->count == list->max) {
        list->data = realloc(list->data, sizeof(Person) * (list->count * 2));
        list->max *= 2;
    }
    
    for (i = list->count; i > 0; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[0] = p;
    list->count++;
}

void insert_last_DAL_2(PersonDynamicArrayList *list, Person p){
    if (list->count == list->max) {
        list->data = realloc(list->data, sizeof(Person) * (list->count * 2));
        list->max *= 2;
    }

    list->data[list->count] = p;
    list->count++;
}

void insert_at_DAL_2(PersonDynamicArrayList *list, Person p, int index){
    int i;
    if (list->count == list->max) {
        list->data = realloc(list->data, sizeof(Person) * (list->count * 2));
        list->max *= 2;
    }

    for (i = list->count; i != index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[i] = p;
    list->count++;
}

void delete_first_DAL_2(PersonDynamicArrayList *list){
    int i;
    for (i = 0; i < list->count - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->count--;
}

void delete_last_DAL_2(PersonDynamicArrayList *list){
    list->count--;
}

void delete_by_name_DAL_2(PersonDynamicArrayList *list, String name){ // last ocurrence
    int i, j;
    for (i = list->count; i >= 0 && strcmp(list->data[i].name, name) != 0; i--) {}
    if (i != -1) {
        for (j = i; j < list->count - 1; j++) {
            list->data[j] = list->data[j+1];
        }
        list->count--;
    }
}

void display_DAL_2(PersonDynamicArrayList list){
    int i;
    for (i = 0; i < list.count; i++) {
        displayPersonInfo(list.data[i]);
    }    
}


/* Singly Linked List */

void insert_first_LL(PersonLinkedList *list, Person p){
    PersonLinkedList temp = (PersonLinkedList) malloc(sizeof(PersonNode));
    if (temp != NULL) {
        temp->elem = p;
        temp->next = *list;
        *list = temp;
    }
}

void insert_last_LL(PersonLinkedList *list, Person p){
    PersonLinkedList *current;
    PersonLinkedList temp = (PersonLinkedList) malloc(sizeof(PersonNode));
    if (temp != NULL) {
        for (current = list; *current != NULL; current = &(*current)->next) {}
        temp->elem = p;
        temp->next = NULL;
        *current = temp;
    }
}

void insert_after_LL(PersonLinkedList *list, Person p, String name){
    PersonLinkedList *current;
    PersonLinkedList temp = (PersonLinkedList) malloc(sizeof(PersonNode));
    if (temp != NULL) {
        for (current = list; *current != NULL && strcmp((*current)->elem.name, name) != 0; current = &(*current)->next) {}
        temp->elem = p;
        temp->next = (*current)->next;
        (*current)->next = temp;
    }
}

void delete_first_LL(PersonLinkedList *list){
    if (*list != NULL) {
        PersonLinkedList temp = *list;
        *list = (*list)->next;
        free(temp);
        temp = NULL;
    }
}

void delete_last_LL(PersonLinkedList *list){
    if (*list != NULL) {
        PersonLinkedList *current;
        for (current = list; (*current)->next != NULL; current = &(*current)->next) {}
        free(*current);
        *current = NULL;
    }
}

void delete_by_city_LL(PersonLinkedList *list, String city){ // all ocurrences
    if (*list != NULL) {
        PersonLinkedList *current, temp;
        for (current = list; *current != NULL; current = &(*current)->next) {
            if (strcmp((*current)->elem.city, city) == 0) {
                temp = *current;
                *current = temp->next;
                free(temp);
            }
        }
    }
}

void display_LL(PersonLinkedList list){
    PersonLinkedList current;
    for (current = list; current != NULL; current = current->next) {
        displayPersonInfo(current->elem);
    }
}


/* Cusor Based List*/

void init_vspace(VSpace *vs){
    int i;
    for (i = MAX_VSPACE - 1; i >= 0; i--) {
        vs->data[i].next = i - 1;
    }
    vs->avail = MAX_VSPACE - 1;
}

Position alloc_space(VSpace *vs){
    Position ret = -1;
    if (vs->avail != -1) {
        ret = vs->avail;
        vs->avail = vs->data[vs->avail].next;
    }
    return ret;
}

void free_space(VSpace *vs, Position index){
    vs->data[index].next = vs->avail;
    vs->avail = index;
}

void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
    Position temp = alloc_space(vs);
    if (temp != -1) {
        vs->data[temp].elem = p;
        vs->data[temp].next = *list;
        *list = temp;
    }
}

void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
    Position *current, temp = alloc_space(vs);
    if (temp != -1) {
        for (current = list; *current != -1; current = &(vs->data[*current].next)) {}
        vs->data[temp].elem = p;
        vs->data[temp].next = *current;
        *current = temp;
    }
}

void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index){
    Position *current, temp = alloc_space(vs);
    if (temp != -1) {
        for (current = list; *current != -1 && *current != index; current = &(vs->data[*current].next)) {}
        // unfinished
    }
}

void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list){
    if (*list != -1) {
        Position temp = *list;
        *list = vs->data[*list].next;
        free_space(vs, temp);
    }
}

void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list){
    if (*list != -1) {
        Position *current;
        for (current = list; vs->data[*current].next != -1; current = &(vs->data[*current].next)) {}
        free_space(vs, *current);
        *current = -1;
    }    
}

void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex){ // all ocurrences
    if (*list != -1) {
        Position *current = list, temp;
        while (*current != -1) {
            if (vs->data[*current].elem.sex == sex) {
                temp = *current;
                current = &(vs->data[*current].next);
                free_space(vs, *current);
            } else {
                current = &(vs->data[*current].next);
            }
        }
    }
} // not working

void display_CBL(VSpace vs, PersonCusorBasedList list){
    int i;
    for (i = list; i != -1; i = vs.data[i].next) {
        displayPersonInfo(vs.data[i].elem);
    }
}