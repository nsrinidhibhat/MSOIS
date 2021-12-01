#include <stdint.h>
#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

typedef struct _node_ Node;

struct _node_
{
    int32_t data;
    Node *next;

};

typedef struct _slist_ Slist;
struct _slist_
{

    Node *head;
    Node *tail;
    uint32_t length;
};

Slist slist_new();
uint8_t slist_lookup(const Slist *list, int32_t key);
uint32_t slist_length(const Slist *list);
Slist* slist_addnode_head(Slist *list,int32_t val);
Slist* slist_addnode_tail(Slist *list,int32_t val);
Slist* slist_delnode_head(Slist *list);
Slist* slist_delnode_tail(Slist *list);
uint32_t slist_min(Slist *list);
uint32_t slist_max(Slist *list);
Slist* slist_add_between(Slist *list,int32_t pos,int32_t val);
uint16_t slist_compare(Slist *list,Slist *list1);
Slist* slist_union(Slist *list,Slist *list1);
Slist* slist_intersection(Slist *list,Slist *list1);
Slist* slist_unique(Slist *list,int32_t val);

#endif // SLIST_H_INCLUDED
