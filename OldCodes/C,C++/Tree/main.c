#include <stdio.h>
#include <stdlib.h>

typedef struct tree
    {
        int info;
        struct tree *left;
        struct tree *right;
    }T;
int main()
{
    int i=1;
    char ch;
    T *root=NULL,*t,*subr,*subl;
    /*root->left=(T *)malloc(sizeof(T));
    root->right=(T *)malloc(sizeof(T));
    */
    t=(T *)malloc(sizeof(T));
    if(i==1)
        root=t;
    {
        printf("Enter Root Info\n");
        scanf("%d",&t->info);
        printf("Enter l for left subtree\n");
        ch=getchar();
        ch=getchar();
        if(ch=='l')
                subl=t->left;
        else
            t->left=NULL;

        printf("Enter r for right subtree\n");
        ch=getchar();
        ch=getchar();
        if(ch=='r')
            subr=t->right;
        else
            t->right=NULL;
    }

    while(t->left!=NULL)
    {
        t->left=t;
        printf("Enter info of left subtree\n");
        scanf("%d",&t->info);
        printf("Enter l for left subtree\n");
        ch=getchar();
        ch=getchar();
        if(ch=='l')
                subl=t->left;
        else
            t->left=NULL;
        printf("Enter r for right subtree\n");
        ch=getchar();
        ch=getchar();
        if(ch=='r')
            subr=t->right;
        else
            t->right=NULL;
    }

    printf("Tree : %d",t->info);
    return 0;
}
