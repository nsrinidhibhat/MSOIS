#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mmb.h"
#include "mmb.c"
#include<string.h>

void test(){

    Slist s1 = slist_new();
    Slist *list= &s1;
    assert (count_cust(list) == 0);

    list = open_acc(list,"Srinidhi","",32,"ABCDEFSB1000","SB","9865478523",2000,"");
    assert(list->head->data.initial_depo == 2000); //  account with 2000 initial deposit and type="SB" is created
    list = open_acc(list,"SAP","",28,"ABCDEFSB1001","SB","9865478523",3000,"");
    assert (list->head->data.age == 28); // Second account is created
    list = open_acc(list,"DSouza","",48,"ABCDEFST1002","STUDENT","9865478523",0,""); // student can have initial amout as 0
    assert(strcmp(list->head->data.acc_type,"STUDENT")==0);
    list = open_acc(list,"Brud","Burt",48,"ABCDEFJO1003","JOINT","9865478523",2200,"");
    assert(strcmp(list->head->data.joint_name,"ravi")==0);


}


int main()
{
    //printf("Hello world!\n");
    test();
    return 0;
}
