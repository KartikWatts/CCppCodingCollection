#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n1;
    int n2;
    int n3;
    int sumh1=0;
    int sumh2=0;
    int sumh3=0;
    int f=1;
    int i,j,k;
    scanf("%d %d %d",&n1,&n2,&n3);
    int h1[n1];
    for(i = 0; i < n1; i++){
       scanf("%d",&h1[i]);
        sumh1=sumh1+h1[i];
    }
    int h2[n2];
    for(j = 0; j < n2; j++){
       scanf("%d",&h2[j]);
         sumh2=sumh2+h2[j];
    }
    int h3[n3];
    for(k = 0; k < n3; k++){
       scanf("%d",&h3[k]);
         sumh3=sumh3+h3[k];
    }

   int max;
   i=j=k=0;
    while(f!=0)
    {
        if(sumh1 > sumh2 && sumh1 > sumh3)
        {
                max= sumh1;
        }
        else if(sumh3 > sumh2 && sumh3 > sumh1)
        {
                max= sumh3;
        }
        else
        {
                max=sumh2;
        }

        if(sumh1 == sumh2 && sumh3==sumh1)
            {
                f=0;
                printf("%d",sumh1);
                break;
            }
        else
        {
            if(max==sumh1)
            {
              sumh1=sumh1-h1[i];
              i++;
            }
            if(max==sumh2)
            {
              sumh2=sumh2-h2[j];
              j++;
            }
            if(max==sumh3)
            {
              sumh3=sumh3-h3[k];
              k++;
            }
        }
    }
    return 0;
}
