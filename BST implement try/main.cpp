#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct bst
{
    int info;
    struct bst *left, *right;
}node;

node *getnode()
{
    node *temp;
    temp= (node *)malloc(sizeof(node));
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void insert(node *root, node *newn)
{
    if(root->info >newn->info)
    {
        if(root->left==NULL)
            root->left=newn;
        else
            insert(root->left, newn);
    }
    else
    {
        if(root->right==NULL)
            root->right=newn;
        else
            insert(root->right,newn);
    }
}

void inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->info;
        inorder(temp->right);
    }
}

node *search(node *root, int key, node **parent)
{
    node *temp;
    temp = root;
    while(temp!=NULL)
    {
        if(temp->info==key)
        {
            cout<<"The Node "<<temp->info<<" is Searched\n";
            return temp;
        }
        *parent=temp;
        if(key <temp->info)
            temp=temp->left;
        else
            temp=temp->right;
    }
    return NULL;
    cout<<"Node Does NOT Exists\n";
}

void Del(node *root, int key)
{
    node *temp,*parent,*temp_succ;
    temp=search(root,key,&parent);

    if(temp->left!=NULL && temp->right!=NULL)
    {
        parent=temp;
        temp_succ=temp->right;
        while(temp_succ->left!=NULL)
        {
            parent=temp_succ;
            temp_succ=temp_succ->left;
        }
        temp->info=temp_succ->info;
        parent->right=NULL;
        return;
    }
    if(temp->left==NULL && temp->right!=NULL)
    {
        if(parent->left==temp)
            parent->left=temp->right;
        else
            parent->right=temp->right;
        temp=NULL;
        free(temp);
    }
    if(temp->left!=NULL && temp->right==NULL)
    {
        if(parent->left==temp)
            parent->left=temp->left;
        else
            parent->right=temp->left;
        temp=NULL;
        free(temp);
    }
    if(temp->left==NULL && temp->right==NULL)
    {
        if(parent->left==temp)
            parent->left=NULL;
        else
            parent->right=NULL;
    }
}

int main()
{
    int act=0,ch=1,key;
    node *parent,*root,*temp,*newn;
    root=NULL;
    while(act!=5)
    {
        cout<<"Choose your action:\n";
        cout<<"1.Create\t 2.Show\t 3.Search\t 4.Delete\t 5.Exit\n";
        cin>>act;
        switch(act)
        {
        case 1:
            while(ch!=0)
            {
            newn = getnode();
            cout<<"Enter the Node\t";
            cin>>newn->info;
            if(root==NULL)
                root=newn;
            else
                insert(root, newn);
            cout<<"Want to Enter more elements: 1.Yes 0.No\t";
            cin>>ch;
            }
        break;
        case 2:
            if(root==NULL)
                cout<<"NO elements in Tree\n";
            else
                inorder(root);
        break;
        case 3:
            cout<<"Enter element to search\t";
            cin>>key;
            temp=search(root,key,&parent);
            cout<<"Parent of Node"<<temp->info<<" is "<<parent->info<<endl;

        break;
        case 4:
            cout<<"Enter element to delete\t";
            cin>>key;
            Del(root,key);
        break;
        default:
            exit(6);
        }
    }
    return 0;
}
