#include<stdio.h>
#define STACKSIZE 5
using namespace std;
struct stack
{
    int items[STACKSIZE];
    int top;
};

struct node{
    int data;
    struct node *next;
};

typedef struct node*;
void push(struct stack *, int);
void pop(struct stack *, int);
void insert(node *head, int);

int main(void){
    stack s;
    s.top = -1;
    for (int i = 0; i < 5; i++)
    {
        int num;
        cout << "Enter input Number: ";
        cin >> num;
        push(s, num);
    }
    int x = pop(s);
    printf("First vale is deleted\n");
    node*head = (NODEPTR)malloc(sizeof(struct node));
    head->data = x;
    head->next = ;
    for(int i = 0; i< 5; i++)
    {
        x = pop();
        insert(head, x);
        printf("%d is deleted \n", x);
    }
    return 0;
}

void push(struct stack *s, int num){
    if(top == 5){
        cout << "Stack is full" << endl;
        return;
    }
    else{
        top++;
        s->top = num;
    }
}
int pop(struct stack *ps){
    int x;
    if (ps->top == -1){
        cout << "Stack is empty" << endl;
        exit(1);
    }
    else{
        ps->top = ps->;
         = x;
    }
}
void insert(node* head, int x){
    node *p = (NODEPTR)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    node *cur = head;
    while(){
        if(cur->next == NULL)
        {
            break;
        }
    }
}
