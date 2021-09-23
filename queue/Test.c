#include <stdio.h>
#include <string.h>

#include "Exercise1.h"

int main(void) {
    // test data --------------------------
    Person p1 = {"Edwin", 'M', "Tagb"};
    Person p2 = {"Roq", 'M', "Iligan"};
    Person p3 = {"France", 'F', "Cebu"};
    Person p4 = {"Nin", 'F', "Cebu"};
    Person p5 = {"Van", 'M', "Cebu"};

    // static array list ------------------
    PersonStaticArrayList mySAL;
    init_SAL(&mySAL);

    insert_first_SAL(&mySAL, p1);
    insert_first_SAL(&mySAL, p2);
    insert_first_SAL(&mySAL, p3);
    insert_last_SAL(&mySAL, p1);
    insert_last_SAL(&mySAL, p2);
    insert_last_SAL(&mySAL, p3);
    insert_at_SAL(&mySAL, p4, 2);
    insert_at_SAL(&mySAL, p5, 1);

    delete_first_SAL(&mySAL);
    delete_last_SAL(&mySAL);
    delete_by_sex_SAL(&mySAL, 'M');

    // display_SAL(mySAL);

    // dynamic array list v1 --------------
    PersonDynamicArrayList myDAL;
    init_DAL(&myDAL);

    insert_first_DAL(&myDAL, p1);
    insert_first_DAL(&myDAL, p2);
    insert_first_DAL(&myDAL, p3);
    insert_last_DAL(&myDAL, p1);
    insert_last_DAL(&myDAL, p2);
    insert_last_DAL(&myDAL, p3);
    insert_at_DAL(&myDAL, p4, 2);
    insert_at_DAL(&myDAL, p5, 5);

    delete_first_DAL(&myDAL);
    delete_first_DAL(&myDAL);
    delete_last_DAL(&myDAL);
    delete_last_DAL(&myDAL);
    delete_by_city_DAL(&myDAL, "Tagb");

    // display_DAL(myDAL);

    // Cursor Based List ----------------

    // void init_vspace(VSpace *vs);
    // Position alloc_space(VSpace *vs);
    // void free_space(VSpace *vs, Position index);
    // void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p);
    // void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p);
    // void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index);
    // void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list);
    // void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list);
    // void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex); // all ocurrences
    // void display_CBL(VSpace vs, PersonCusorBasedList list);

    return 0;
}