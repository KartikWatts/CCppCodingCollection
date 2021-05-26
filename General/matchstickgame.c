#include<stdio.h>

int main(){
    int match=21;

    int turn=0;
    while (match>0)
    {
        printf("%d\n", match);
        if(match==1){
            match=0;
            if(turn%2==0){
                printf("Player Loose\n");
            }
            else{
                printf("Computer Loose\n");
            }
        }
        else if(match<=5){
            if(turn%2==0)
                match=2;
            else
                match=1;
        }
        else
            match=match-4;
        turn++;
    }
}