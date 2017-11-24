#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
}T;

T *getnode();

void insert(T*, T*);

int main()
{
    T *newn, *root;
    int ch;
    char ans;
    root=NULL;
    do
    {
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            root=NULL;
            do
            {
                newn=getnode();
                printf("Enter node data  ");
                scanf("%d",&newn->data);
                if(root==NULL)
                    root=newn;
                else
                    insert(root,newn);
                printf("Enter more??  ");
                ans=getchar();
                ans=getchar();
            }
            while(ans=='y');
            break;
        }
    }
    while(ch!=5);
    return 0;
}

T *getnode()
{
    T *temp;
    temp = (T *) malloc(sizeof(T));
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(T *root,T *newn)
{
    char c;
    printf("Enter right or left");
    scanf("%c",&c);
    if(c=='r')
    {
        if(root->right==NULL)
            root->right=newn;
        else
        {
            insert(root->right,newn);
        }
    }
    else
    {
        if(root->left==NULL)
            root->left=newn;
        else
            insert(root->left,newn);
    }
}
