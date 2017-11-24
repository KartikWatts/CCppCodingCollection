#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,test=0,i=0;
    struct task
    {
        char ch;
    }t[1000];
    scanf("%d",&T);
    while(test<T && T<=1000)
    {
        t[i].ch=getchar();
        t[i].ch=getchar();
        i++;
        test++;
    }

    for(i=0;i<T;i++)
    {
        if(t[i].ch=='b'||t[i].ch=='B'||t[i].ch=='c'||t[i].ch=='C'||t[i].ch=='d'||t[i].ch=='D'||t[i].ch=='f'||t[i].ch=='F')
        {
            if(t[i].ch=='b' || t[i].ch=='B')
                printf("BattleShip\n");
            if(t[i].ch=='c' || t[i].ch=='C')
                printf("Cruiser\n");
            if(t[i].ch=='d' || t[i].ch=='D')
                printf("Destroyer\n");
            if(t[i].ch=='f' || t[i].ch=='F')
                printf("Frigate\n");
        }
    }
    return 0;
}
