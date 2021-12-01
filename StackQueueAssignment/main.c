#include "stack.h"
#include "queue.h"
#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>


int balancing_symbols(char c[10])
{

	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	for(int i=0;i<strlen(c);i++)
	{
		if(c[i] == '[' || c[i] == '(' || c[i] == '{')
		{
			stk = stack_push(stk,c[i],&res);
			continue;
		}
		else if(c[i] == ']' && stk->data[stk->top]=='[')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else if(c[i] == ')' && stk->data[stk->top]=='(')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else if(c[i] == '}' && stk->data[stk->top]=='{')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else
		{
			assert(stk->top==2 || stk->top == -1);
			return 0;
		}

	}
	stk = stack_peek(stk,&res);
	assert(stk->top == -1);

	return 0;
}

int postfix(char p[20])
{
	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	for(int i=0;i<strlen(p);i++)
    {
        if(isdigit(p[i]))
        {
            stk=stack_push(stk,p[i],&res);
         }
        else
        {
           char a,b;
            int c=0;
            a = stk->data[stk->top];
            stk = stack_pop(stk,&res);
            b = stk->data[stk->top];
            stk = stack_pop(stk,&res);
            if(p[i]=='+')
            {
            c = a -'0' + b - '0';
            //printf("%d",c);
            }
            else if(p[i]=='-')
            {
                c = (b-'0') - (a-'0');
            }
            else if(p[i]=='*')
            {
                c = (b-'0') * (a-'0');
            }
            else if(p[i]=='/')
            {
                c = (b-'0')/(a-'0');
            }
            char pf = c+'0';
            stk = stack_push(stk,pf,&res);
        }
    }

stk = stack_peek(stk,&res);
assert(res.data=='6');
}




void constant_memory()
{
Queue k= queue_new(10);
Queue *q=&k;
Queue_Result Qres;

q=queue_add(q,10,&Qres);
q=queue_add(q,20,&Qres);
q=queue_add(q,30,&Qres);
q=queue_add(q,40,&Qres);

assert(q->count==4);
int d2count=1;
int d3count=q->count;

while(d2count<=d3count)
{
int dcount=1;
while(dcount<q->count)
{
	q = queue_delete(q,&Qres);
	q = queue_add(q,Qres.data,&Qres);
	dcount++;
}
	q = queue_delete(q,&Qres);

d2count++;
}
assert(Qres.data==10);
}

void stackTOqueue()
{
	Stack stk = stack_new(10);
Stack *s=&stk;
Stack_Result Sres;

Queue k= queue_new(10);
Queue *q=&k;
Queue_Result Qres;

s = stack_push(s,93,&Sres);
s = stack_push(s,53,&Sres);
s = stack_push(s,73,&Sres);
s = stack_push(s,83,&Sres);

int element = 53;
int count = 0;
int i=0;
while(i<=s->top+1)
{
s = stack_peek(s,&Sres);
if(Sres.data==element)
{
	break;
}
else
{
	s = stack_pop(s,&Sres);
	q = queue_add(q,Sres.data,&Qres);
	count++;
}
i++;
}

int dcount=count;
int d1count=count;
while(count!=0)
{
	q= queue_delete(q,&Qres);
	s= stack_push(s,Qres.data,&Sres);
	count--;
}
s = stack_peek(s,&Sres);
assert(Sres.data==73);

while(dcount!=0)
{
	s=stack_pop(s,&Sres);
	q=queue_add(q,Sres.data,&Qres);
	dcount--;
}

s = stack_peek(s,&Sres);
assert(Sres.data==53);


while(d1count!=0)
{
	q= queue_delete(q,&Qres);
	s= stack_push(s,Qres.data,&Sres);
	d1count--;
}

s = stack_peek(s,&Sres);
assert(Sres.data==83);

}

Stack* deleteQueue(Stack *s1,Stack *s2,Stack_Result Sres1,Stack_Result Sres2)
{
	while(s1->top>-1)
	{
	s1 = stack_pop(s1,&Sres1);
	int32_t popelement = Sres1.data;
	s2 = stack_push(s2,popelement,&Sres2);
	}
	s2 = stack_pop(s2,&Sres2);
	return s2;
}


void queueUsingStacks()
{
	Stack stk1 = stack_new(10);
	Stack *s1=&stk1;
	Stack_Result Sres1;

	s1 = stack_push(s1,10,&Sres1);
	s1 = stack_push(s1,20,&Sres1);
	s1 = stack_push(s1,50,&Sres1);

	Stack stk2 = stack_new(10);
	Stack *s2=&stk2;
	Stack_Result Sres2;


	s2 = deleteQueue(s1,s2,Sres1,Sres2);
	s1 = stack_peek(s1,&Sres1);
	assert(s1->top==-1);

	s2 = stack_peek(s2,&Sres2);
	assert(Sres2.data==20);

}




int main()

{



	char c[10] = "}((]";
	char c1[20] = "[({})]";

  	balancing_symbols(c);
	balancing_symbols(c1);


    char p[20]="423+1*+3-";
    postfix(p);

    Queue queue = queue_new(10);
    Queue *q = &queue;

    Queue_Result res;

    q = queue_add(q,10,&res);
    assert(q->count==1);
    assert(q->data[q->head-1] == 10);
        q = queue_add(q,20,&res);
        q = queue_add(q,30,&res);
    assert(q->data[q->head-1]==30);
    assert(q->data[q->tail]==10);

    q = queue_delete(q,&res);
    assert(res.data==10);
    assert(q->data[q->tail]==20);


    constant_memory();



    stackTOqueue();


    queueUsingStacks();


return 0;
}
