#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int info;
    struct link *next;
}ll;

ll start, *node, *prev, *temp;

void create(ll* node)
{
    char ch;
    int i=1;
    start.next=NULL;
    node=&start;
    printf("Enter b to break");
    ch=getchar();
    while(ch !='b')
    {
        node->next=(ll*) malloc(sizeof(ll));
        node=node->next;
        printf("Enter value of node %d\n",i);
        scanf("%d",&node->info);
        node->next=NULL;
        printf("Enter b to break");
        ch=getchar();
        ch=getchar();
        i++;
    }
}

void doubly(ll* node)
{
    node=start.next;
    prev=&start;

}

void display(ll* node)
{
    node=start.next;
    printf("Created Linked list is\n");
    while(node)
    {
    printf("%d\n",node->info);
    node=node->next;
    }
}

int main()
{
    ll* node=(ll*)malloc(sizeof(ll));
    create(node);
    display(node);
    return(0);
}
