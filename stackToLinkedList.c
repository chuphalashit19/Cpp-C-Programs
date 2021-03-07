#include<stdio.h>
#define STACKSIZE 5
struct stack
{
    int items[STACKSIZE];
    int top;
};

struct node{
    int data;
    struct node *next;
};

typedef struct node* NODE;
void push(struct stack *, int);
void pop(struct staqck *, int);
void insert(node *head, int);
int main(void){
    stack s;
    s.top = -1;
    for (int i = 0; i < 5; i++)
    {
        int num;
        cout <<
    }
}
