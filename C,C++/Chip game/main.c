#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r,c,tr,tc,turn=0;
    printf("Enter the no. of rows and columns\n");
    scanf("%d %d",&r,&c);

    tr=1,tc=1;
    /*tuzik vanya
    row +3 maximum
    col +2 maximum*/
    while(tr!=r || tc!=c)
    {
        if(tr!=r)
        {
            turn++;
            if(tr<r-3)
                tr=tr+3;
            else
                tr=r;
        }

        if(tr==r && tc!=c)
        {
            turn++;
            if(tc<c-2)
                tc=tc+2;
            else if(tc==c-2 || tc==c-1)
                tc=c;
        }
                if(tc==c && tr==r)
                {
                    printf("No. of Turns = %d\nWinner : ",turn);
                    if(turn%2==0)
                        printf("Vanya");
                    else
                        printf("Tuzic");
                }
    }

    return 0;
}
