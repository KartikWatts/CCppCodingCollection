#include <stdio.h>
#include <stdlib.h>

void christmastree(int total_height){
    int n= total_height;
    int space_per_height= 2; //Extra Space Required per Unit Height Increase, also for every column height
    
    // Body of Tree
    while (n > 0) {
        int leftspace, innerspace;
        for (int colums = 1; colums <= 3; colums++) {
            for (leftspace = colums; leftspace < n + space_per_height; leftspace++) {
                printf(" ");
            }
            printf("/");
            
            int total_inner_space= (total_height-n)*space_per_height + (colums-1)*space_per_height; 
            // Inner space increase by 2, according to tree height; also Inner space increase by 2 for every column within that height as well
            
            for (innerspace = 1; innerspace <= total_inner_space; innerspace++)
            {
                if(colums==3){
                    // For every first and final space of final column of every height, '_' has to be placed
                    if(innerspace==1 || innerspace== total_inner_space){
                        printf("_");
                        continue;
                    }
                }
                // In the final column of final height, all the inner-space will be '_'
                if(n==1 && colums==3){
                    printf("_");
                    continue;
                }
                // At every 4th inner-space 'i' will be placed, but it starts this pattern from inner-space:2 
                if((innerspace+2)%4==0)
                    printf("i");
                else
                    printf(" ");
            }

            printf("\\");
            
            printf("\n");
        }
        n--;
    }

    // Base of Tree: ## (Fixed Length:3)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= total_height; j++)
        {
            printf(" ");
        }
        printf("##\n");
    }

}

int main()

{
    christmastree(10);

    return 0;

}