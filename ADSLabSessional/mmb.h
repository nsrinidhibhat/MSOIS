#ifndef MMB_H_INCLUDED
#define MMB_H_INCLUDED
#include <stdint.h>
#include <uchar.h>

typedef struct _cust_ Cust;
struct _cust_ {
    char32_t *name;
    char32_t *name2;
    int32_t age;
    char32_t *pan;
    char32_t *acc_type;
    char32_t *phone;
    int32_t initial_depo;
    char32_t acc_no;
};

typedef struct _customer_node_ Node;

struct _customer_node_ {
    Cust data;
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
uint32_t count_cust(const Slist *list);

Slist* open_acc(Slist *list,char32_t *name,char32_t *joint_name,int32_t age,char32_t *pan,char32_t *acc_type,char32_t *phone,int32_t initial_depo,char32_t acc_no);
Slist* credit(Slist *list,int amount);
Slist* debit(Slist *list,int amount);
uint32_t balance(const Slist *list,char32_t acc_no);
uint32_t count_credit_debit(const Slist *list);



#endif // MMB_H_INCLUDED
