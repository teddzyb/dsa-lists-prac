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

    // dynamic array list -----------------
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

    // Singly Linked List ----------------

    PersonLinkedList myLL = NULL;

    insert_first_LL(&myLL, p1);
    insert_first_LL(&myLL, p2);
    insert_last_LL(&myLL, p3);
    insert_last_LL(&myLL, p4);
    insert_after_LL(&myLL, p5, "France");

    delete_first_LL(&myLL);
    delete_last_LL(&myLL);
    delete_by_city_LL(&myLL, "Tagb");

    // display_LL(myLL);

    // Cursor Based List -----------------

    VSpace mySpace;
    PersonCusorBasedList myCB = -1;
    init_vspace(&mySpace);

    insert_first_CBL(&mySpace, &myCB, p1);
    insert_first_CBL(&mySpace, &myCB, p2);
    insert_last_CBL(&mySpace, &myCB, p3);
    insert_last_CBL(&mySpace, &myCB, p4);
    // insert_at_CBL(&mySpace, &myCB, p5, 2);

    delete_first_CBL(&mySpace, &myCB);
    delete_last_CBL(&mySpace, &myCB);
    // delete_by_sex_CBL(&mySpace, &myCB, 'F');

    display_CBL(mySpace, myCB);

    // Circular Array Queue --------------

    // int get_queue_length(CircularArrayQueue list);
    // PersonLinkedList get_all_females(CircularArrayQueue list);
    // PersonDynamicArrayList remove_all_males(CircularArrayQueue *list);

    return 0;
}