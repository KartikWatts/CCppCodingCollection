/*Create the simple binary tree and recursive traversal*/
/* Data Structures Using C by UDIT AGARWAL */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct bin
{
    int data;
    struct bin *left;
    struct bin *right;
}node;

void insert (node *, node*);
void inorder (node *);
void preorder (node *);
void postorder (node *);
node *get_node();

int main( )
{
    int choice;
    char ans = 'n';
    node *newn,*root;
    root = NULL;
    //clrscr();

do
{
    printf("\n Program for implementing simple binary tree\n");
    printf("\n**********************************************\n");
    printf("\n 1.create");
    printf("\n 2.inorder");
    printf("\n 3.preorder");
    printf("\n 4.postorder");
    printf("\n 5.exit");
    printf("\n \t Enter Your choice: ");

    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        root = NULL;
        do
        {
            /*newn used here*/
            newn=get_node();
            printf("\n enter the element\n");
            scanf("%d",& newn->data);
            if(root == NULL)
                root= newn;
            else
                insert(root, newn);
            printf("\n Do you want to enter more elements?(y/n)\n");
            ans = getch();
        }
        while(ans== 'Y'|| ans=='y');
        //clrscr();
        break;

        case 2:
            if(root == NULL)
                printf("Tree is not created!");
            else
                inorder(root);
        break;

        case 3:
            if(root ==NULL)
                printf("Tree is not created!");
            preorder (root);
        break;

        case 4:
            if(root == NULL)
                printf("Tree is not created!");
            postorder(root);
        break;
    }
}
while(choice!=5);
return 0;
}
//void main() ends here

node *get_node()
{
    node *temp;
    temp = (node *) malloc(sizeof(node));
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(node *root, node *newn)
{
    char ch;
    printf("\n Where to insert left/right of %d:\n", root->data);
    ch=getche();
    if((ch=='R') || (ch=='r'))
    {
        if(root->right == NULL)
        {
            root->right=newn;
        }
        else
            insert(root->right,newn);
    }
    else
    {
        if(root->left== NULL)
        {
            root->left=newn;
        }
        else
            insert(root->left,newn);
    }
}

void inorder(node *temp)
{
    if(temp!= NULL)
    {
        inorder(temp->left);
        printf("%d", temp->data);
        inorder(temp ->right);
    }
}

void preorder(node *temp)
{
    if(temp != NULL)
    {
    printf("%d",temp->data);
    preorder(temp->left);
    preorder(temp->right);
    }
}

void postorder(node *temp)
{
    if(temp!= NULL)
    {
        postorder(temp-> left);
        postorder(temp->right);
        printf("%d",temp->data);
    }
}
