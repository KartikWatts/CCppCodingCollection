#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int info;
    struct link *next;
}ll;

ll start, *prev, *new1;

void create(ll *node)
{
    char ch;
    start.next=NULL;
    node=&start;
    int i=1;
    printf("\n Enter b to break");
    ch=getchar();
    while(ch !='b')
    {
        node->next=(ll*) malloc(sizeof (ll));
        node=node->next;
        printf("Input value of node %d\n",i);
        scanf("%d",&node->info);
        node->next=NULL;
        printf("Enter b to break");
        ch=getchar();
        ch=getchar();
        i++;
    }
}

void insert(ll *node)
{
    node=start.next;
    prev=&start;

    while(node)
    {
        node=node->next;
        prev=prev->next;
    }
    if(node==NULL)
    {
        new1=(ll*)malloc(sizeof(ll));
        new1->next=node;
        prev->next=new1;
        printf("Input the last node value \n");
        scanf("%d",&new1->info);
    }
}

void display(ll *node)
{
    node=start.next;
    while(node)
    {
        printf("%d\n",node->info);
        node=node->next;
    }
}
int main()
{
    ll *node=(ll*)malloc(sizeof(ll));
    create(node);
    printf("Created Linked List is\n");
    display(node);
    insert(node);
    printf("After Insertion LL is\n");
    display(node);
    return 0;
}
