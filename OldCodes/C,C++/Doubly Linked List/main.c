#include <stdio.h>
#include <stdlib.h>

typedef struct list
    {
        int info;
        struct list *next;
        struct list *prev;
    }ln;

ln start,*node,*tmp,*new1;
int main()
{
    int i=1;
    char ch;
    start.next=NULL;
    start.prev=NULL;
    node=&start;
    new1=start.next;
    printf("Enter b to break");
    ch=getchar();
    while(ch!='b')
    {
        node->next=(ln*)malloc(sizeof(ln));
        new1->prev=(ln*)malloc(sizeof(ln));
        node=node->next;
        node=new1;
        new1->prev=node;
        printf("Enter value of node %d\n",i);
        scanf("%d",&node->info);
        node->next=NULL;
        printf("Enter b to break");
        ch=getchar();
        ch=getchar();
        i++;
    }

    node=start.next;
    printf("The Actual created linked list is\n");
    while(node)
    {
        printf("%d\n",node->info);
        node=node->next;
    }
    printf("The Reverse ordered linked list is\n");
    while(node->prev)
    {
        printf("%d",node->info);
        node=node->prev;
    }
    return 0;
}
