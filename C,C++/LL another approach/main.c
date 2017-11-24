#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int info;
    struct link *next;
}ll;

ll start, *prev, *new1,*temp;
int lno,a[20];
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

void traverse(ll *node)
{
    lno=0;
    node=start.next;
    prev=&start;

    while(node)
    {
        a[lno]=node->info;
        printf("Value of current node is\t %d\n",a[lno]);
        node=node->next;
        prev=prev->next;
        lno++;
    }
}

void display(ll *node)
{
    node=start.next;
    while(node)
    {
        printf("%d\t",node->info);
        node=node->next;
    }
}

void sort(ll *node)
{
    int i,j,tmp;
    node=start.next;
    prev=&start;
    for (i=0;i<=lno;i++)
    {
        for(j=i+1;j<=lno;j++)
        {
           if(a[i]>a[j])
           {
               tmp=a[i];
               a[i]=a[j];
               a[j]=tmp;
           }
        }
    }

    for(i=1;i<=lno;i++)
    {
        printf("%d\t",a[i]);
    }
}

void rev()
{
        int j=lno,i=0,tmp;
        while(i<j)
        {
            tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
            i++;
            j--;
        }

        printf("\nReversed LL is\n");
        for(i=0;i<lno;i++)
            printf("%d\t",a[i]);
}
int main()
{
    ll *node=(ll*)malloc(sizeof(ll));
    create(node);
    traverse(node);
    printf("\nCreated Linked List is\n");
    display(node);
    printf("\nSorted Linked List is\n");
    sort(node);
    rev(node);
    return 0;
}
