#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "slist.h"

Slist slist_new()
{

    Slist s1 = {NULL,NULL,0};
    return s1;
}

uint32_t slist_length(const Slist *list)
{
    assert(list != NULL);
    return list->length;
}

//helper function which is not visible to outside

static Node* _get_new_node_(int32_t val)
{

    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->next=NULL;

    return newnode;
}

//Adding node at the head location
Slist* slist_addnode_head(Slist *list,int32_t val)
{
    assert(list != NULL);
    Node *new_node = _get_new_node_(val);
    new_node->next = list->head;
    list->head=new_node;

    if(list->tail == NULL)
    {
        list->tail = new_node;
    }
    ++list->length;

    assert( (list->length == 1 && list->head == list->tail) ||
            (list->length > 1 && list->head != list->tail)
          );

    return list;
}

//Adding node at the tail of the list
Slist* slist_addnode_tail(Slist *list,int32_t val)
{
    assert(list != NULL);
    Node *new_node = _get_new_node_(val);
    if(list->tail != NULL)
    {
        list->tail->next=new_node;
        list->tail = new_node;
    }
    else
    {
        list->head=list->tail=new_node;
    }
    ++list->length;

    assert( (list->length == 1 && list->head == list->tail) ||
            (list->length > 1 && list->head != list->tail)
          );
    return list;
}

//Searching for a key in the list
uint8_t slist_lookup(const Slist *list,int32_t key)
{

    assert(list != NULL);
    Node *cur = list->head;

    for(cur=list->head; cur!=NULL; cur=cur->next)
    {
        if(cur->data == key)
        {
            break;
        }
    }
    return (cur != NULL);

}

//Deleting the node from the head
Slist* slist_delnode_head(Slist *list)
{

    assert (list != NULL);
    Node *temp;
    if (list->head != NULL)
    {
        temp = list->head;
        list->head=list->head->next;
        if (list->head == NULL)
        {
            list->tail = NULL;
        }
        --list->length;
        free(temp);
    }
    return list;

}

//Deleting the node from the tail
Slist* slist_delnode_tail(Slist *list)
{

    assert(list != NULL);
    Node *last,*cur;

    if(list->tail != NULL)
    {
        last = list->tail;
        if(list->head==list->tail)
        {
            list->head=list->tail=NULL;
        }
        else
        {
            for(cur=list->head; cur->next != last; cur=cur->next);
            list->tail = cur;
            cur->next=NULL;
        }
        --list->length;
        free(last);
    }
    return list;
}

//Finding the minimum value from the list
uint32_t slist_min(Slist *list)
{
    assert(list != NULL);
    Node *cur = list->head;
    int min = cur->data;
    for(cur=list->head; cur!=NULL; cur=cur->next)
    {
        if(cur->data < min)
            min = cur->data;
    }
    return min;
}

//Finding the maximum value from the list
uint32_t slist_max(Slist *list)
{

    assert(list != NULL);
    Node *cur = list->head;
    int max = cur->data;
    for(cur=list->head; cur!=NULL; cur=cur->next)
    {
        if(cur->data > max)
            max = cur->data;
    }
    return max;
}

//Add the node in the moiddle of the list
Slist* slist_add_between(Slist *list,int32_t pos,int32_t newval)
{
    assert(list != NULL);
    Node *cur = list->head;
    for(cur=list->head; cur!=NULL; cur=cur->next)
    {
        if(cur->data == pos)
            break;
    }
    Node *new_node = _get_new_node_(newval);
    new_node->next=cur->next;
    cur->next=new_node;
    ++list->length;
    return list;
}

//Deleting the node from the middle
Slist* slist_delete_between(Slist *list,int32_t pos)
{

    assert(list != NULL);
    Node *cur = list->head;
    while(cur->next->data!=pos)
    {
        cur=cur->next;
    }
    cur->next=cur->next->next;
    --list->length;
    return list;
}

//Reversing the list
Slist* slist_reverse(Slist *list)
{

    assert(list != NULL);
    Node *prev,*curr;
    if(list->head != NULL)
    {
        prev = list->head;
        list->head = list->head->next;
        curr=list->head;
        prev->next=NULL;
        while(list->head != NULL)
        {
            list->head = list->head->next;
            curr->next = prev;
            prev = curr;
            curr = list->head;
        }
        list->head=prev;
    }
    return list;

}

//Comparing the two lists
uint16_t slist_compare(Slist *list,Slist *list1)
{

    assert((list && list1) != NULL);
    while((list->head && list1->head) != NULL)
    {
        if(list->head->data != list1->head->data)
        {
            return 0;
        }
        list->head = list->head->next;
        list1->head=list1->head->next;
    }
    return 1;
}

//Union of two list
Slist* slist_union(Slist *list,Slist *list1)
{

    assert((list && list1) != NULL);
    Node *cur = list->head;
    for(cur=list->head; cur->next!=NULL; cur=cur->next);
    Node *cur2 = list1->head;
    while(cur2 != NULL)
    {
        int res = slist_lookup(list,cur2->data);
        if (!res)
        {
            Node *new_node = _get_new_node_(cur2->data);
            cur->next = new_node;
            cur=cur->next;
            ++list->length;
        }
        cur2 = cur2->next;
    }
    return list;
}
//Intersection of two lists
Slist* slist_intersection(Slist *list,Slist *list1)
{

    assert((list && list1) != NULL);
    Slist s3 = slist_new();
    Slist *list2= &s3;
    Node *cur = list->head;
    for(cur=list->head; cur!=NULL; cur=cur->next)
    {
        int res = slist_lookup(list1,cur->data);
        if(res==1)
        {
            list2 = slist_addnode_tail(list2,cur->data);
        }
    }
    return list2;
}

//Creating the Unique list
Slist* slist_unique(Slist *list,int32_t val)
{

    assert(list != NULL);
    int res = slist_lookup(list,val);
    if(!res)
        list = slist_addnode_tail(list,val);
    return list;

}
