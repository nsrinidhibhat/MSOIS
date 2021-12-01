#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"

void test_empty_list()
{

    Slist s1 = slist_new();
    Slist *list= &s1;
    assert (slist_length(list) == 0);
}
void test_add_at_head()
{

    Slist s1 = slist_new();
    Slist *list= &s1;
    assert (slist_length(list) == 0);
    list = slist_addnode_head(list,10);
    assert (slist_length(list)==1);
    list = slist_addnode_head(list,20);
    list = slist_addnode_head(list,30);
    assert (slist_length(list)==3);
    assert (slist_lookup(list, 20) == 1);

}
void test_add_at_tail()
{

    Slist s1 = slist_new();
    Slist *list= &s1;
    assert (slist_length(list) == 0);
    list = slist_addnode_tail(list,10);
    assert (slist_length(list)==1);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);
    assert (slist_length(list)==3);
    assert (slist_lookup(list, 20) == 1);

    //Finding the minimum and maximum values from the list
    assert(slist_min(list)==10);
    assert(slist_max(list)==30);

    //Adding the new value 50 after the value 20
    list = slist_add_between(list,20,50);
    assert((list->head->next->next->data)==50);
    assert (slist_length(list)==4);

    //Deleting the specified value from the list
    list = slist_delete_between(list,50);
    assert(slist_length(list)==3);

    //Reversing the list
    list=slist_reverse(list);
    assert(list->head->data == 30);


    //creating the seperate list
    Slist s2 = slist_new();
    Slist *list1= &s2;
    list1 = slist_addnode_tail(list1,30);
    list1 = slist_addnode_tail(list1,20);
    list1 = slist_addnode_tail(list1,40);

    //comparing the list
    int res=slist_compare(list,list1);
    assert(res==0); //values of the lists are not same


}
void test_set_operation()
{
    Slist s1 = slist_new();
    Slist *list= &s1;
    list = slist_addnode_head(list,10);
    list = slist_addnode_head(list,20);
    list = slist_addnode_head(list,30);

    Slist s2 = slist_new();
    Slist *list1= &s2;
    list1 = slist_addnode_tail(list1,30);
    list1 = slist_addnode_tail(list1,20);
    list1 = slist_addnode_tail(list1,40);

    //Union of two lits
    list=slist_union(list,list1);
    assert (slist_length(list)==4);

    //creating the unique list
    Slist s3 = slist_new();
    Slist *list2= &s3;
    list2 = slist_unique(list2,10);
    list2 = slist_unique(list2,20);
    list2 = slist_unique(list2,30);
    list2 = slist_unique(list2,30);
    list2 = slist_unique(list2,80);
    assert (slist_length(list2)==4);

    //intersection of two lists
    Slist s4 = slist_new();
    Slist *list_intersect= &s4;
    list_intersect = slist_intersection(list,list1);
    assert(slist_length(list_intersect)==3);//Here list={10,20,30,40},list 1={20,30,40}
}

void test_delete_head()
{

    Slist s1 = slist_new();
    Slist *list= &s1;
    list = slist_addnode_tail(list,10);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);

    list = slist_delnode_head(list);
    assert(slist_length(list)==2);
    assert (slist_lookup(list, 10) == 0);
}
void test_delete_tail()
{
    Slist s1 = slist_new();
    Slist *list= &s1;
    list = slist_addnode_tail(list,10);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);
    list = slist_delnode_tail(list);
    assert(slist_length(list)==2);
    assert (slist_lookup(list, 30) == 0);
}
int main()
{
    test_empty_list();
    test_add_at_head();
    test_add_at_tail();
    test_delete_head();
    test_delete_tail();
    test_set_operation();
    return 0;
}

