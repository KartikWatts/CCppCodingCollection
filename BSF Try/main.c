#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef struct tnode
    {
        int data;
        struct tnode *l;
        struct tnode *r;
    }node;
    root =NULL;
    root->l=root->r=NULL;
    node *root,*newn;
    while(ch!='n')
    {
        if(root==NULL)
        {
            root=(node *)malloc(sizeof(node));
            printf("Enter Root data\n");
            scanf("%d",&root->data);
            ptr=root;
        }
        else
        {
            ptr=root;
            pptr=ptr;
            newn=(root *)malloc(sizeof(root));
            printf("Enter data\n");
            scanf("%d",&newn->data);
            while(ptr!=NULL)
            if(newn->data > ptr->data)
            {
                ptr=ptr->r;
                if(ptr==NULL)
                    pptr->r=newn;
                else
                {
                    ptr=ptr->l;
                    if(ptr==NULL)
                        pptr->l=newn;
                }
            }
        }
    }

    return 0;
}
