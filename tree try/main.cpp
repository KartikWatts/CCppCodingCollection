#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct tree
{
    int info;
    struct tree *left;
    struct tree *right;
}node;

node *getnode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void preorder(node *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->info<<"\t";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->info<<"\t";
        inorder(temp->right);
    }
}

void postorder(node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->info<<"\t";
    }
}


void insert(node *root, node *newn)
{
    cout<<"Enter this data in Left or Right of "<<root->info<<"\t";
    char ch=getchar();
    ch=getchar();
    if(ch=='r')
    {
        if(root->right==NULL)
            root->right=newn;
        else
            insert(root->right,newn);
    }
    else
    {
        if(root->left==NULL)
            root->left=newn;
        else
            insert(root->left,newn);
    }
}

int main()
{
    node *newn,*root;
    root = NULL;
    char ans;
do
{
    newn = getnode();
    cout<<"Enter the data in node \t";
    cin>>newn->info;
    if(root==NULL)
        root=newn;
    else
        insert(root,newn);
    cout<<"Do you want to enter more nodes \t";
    ans=getchar();
    ans=getchar();
}
while(ans=='y');
if(ans=='n')
{
    int choice=0;
     while(choice!=4)
    {
    cout<<"What type of Traversal you want \n";
    cout<<"1->Preorder\t 2->Inorder\t 3->Postorder\t 4->Exit\n";
    cin>>choice;

    switch(choice)
    {
        case 1:
            preorder(root);
        break;
        case 2:
            inorder(root);
        break;
        case 3:
            postorder(root);
        break;
        case 4:
            exit(4);
    }
    }
}
    return 0;
}
