#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,A[100];
    scanf("%d",&N);
    if(N>=1 && N<=100)
    {
    for(i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
        if(A[i]<0 || A[i]>1000)
            exit(0);
    }
    for(i=N-1;i>=0;i--)
        printf("%d\n",A[i]);
    }
    return 0;
}
