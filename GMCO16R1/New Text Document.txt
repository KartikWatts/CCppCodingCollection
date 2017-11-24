#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,i,k;
    char last;
    struct co
    {
        int no;
        char str[50],rule[10];
    }C[300];

    scanf("%d",&T);
    if(T>=1 && T<=300)
    {
    for(i=0;i<=T;i++)
    {
        C[i].no=i;
        gets(C[i].str);
        if(strlen(C[i].str)>=3 && strlen(C[i].str)<=50)
    {
    k=0;
    while(C[i].str[k])
    {
        k++;
        if(C[i].str[k]=='\0')
        {
            last=C[i].str[k-1];
            if(last=='a' || last=='e' || last=='i' || last=='o' ||last=='u')
                strcpy(C[i].rule,"a queen");
            else if(last=='y')
                strcpy(C[i].rule,"nobody");
            else
                strcpy(C[i].rule,"a king");
        }
    }
    }
    }
    }


    for(i=1;i<=T;i++)
    {
        printf("Case #%d: %s is ruled by %s.\n",C[i].no,C[i].str,C[i].rule);
    }
    return 0;
}
