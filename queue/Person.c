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
    printf("{%s | %c | %s}", p.name, p.sex, p.city);
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
        printf("%s | %c | %s\n", list.data[i].name, list.data[i].sex, list.data[i].city);
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
        printf("%s | %c | %s\n", list.data[i].name, list.data[i].sex, list.data[i].city);
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

// void delete_by_name_DAL_2(PersonDynamicArrayList *list, String name){ // last ocurrence
//     int i, j;
//     for (i = 0; i < list->count && strcmp(list->data[i].city, city) != 0; i++) {}
//     if (i != list->count) {
//         for (j = i; j < list->count - 1; j++) {
//             list->data[j] = list->data[j+1];
//         }
//         list->count--;
//     }
// }

void display_DAL_2(PersonDynamicArrayList list){
    int i;
    for (i = 0; i < list.count; i++) {
        printf("%s | %c | %s\n", list.data[i].name, list.data[i].sex, list.data[i].city);
    }    
}


/* Singly Linked List */

// void insert_first_LL(PersonLinkedList *list, Person p);
// void insert_last_LL(PersonLinkedList *list, Person p);
// void insert_after_LL(PersonLinkedList *list, Person p, String name);
// void delete_first_LL(PersonLinkedList *list);
// void delete_last_LL(PersonLinkedList *list);
// void delete_by_city_LL(PersonLinkedList *list, String city); // all ocurrences
// void display_LL(PersonLinkedList list);


/* Cusor Based List*/

void init_vspace(VSpace *vs);
Position alloc_space(VSpace *vs);
void free_space(VSpace *vs, Position index);
void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p);
void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p);
void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index);
void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list);
void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list);
void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex); // all ocurrences
void display_CBL(VSpace vs, PersonCusorBasedList list);