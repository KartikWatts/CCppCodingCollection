#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

int main()
{
    int T,n;
    cin>>T;
    while(T>0)
    {
        int i, j = 0, k = 0, x, len;
        cin>>n;
        char str[n],str1[n][n], temp;
    scanf(" %[^\t\n]s",&str);
    k=0;
/* reads into 2d character array */
    for (i = 0;str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            str1[k][j]='\0';
            k++;
            j=0;
        }
        else
        {
            str1[k][j]=str[i];
            j++;
        }
    }
    str1[k][j] = '\0';

/* reverses each word of a given string */
    for (i = 0;i <= k;i++)
    {
        len = strlen(str1[i]);
        for (j = 0, x = len - 1;j < x;j++,x--)
        {
            temp = str1[i][j];
            str1[i][j] = str1[i][x];
            str1[i][x] = temp;
        }
    }
    for (i = 0;i <= k;i++)
    {
        printf("%s ", str1[i]);
    }
    cout<<endl;
    T--;
    }
    return 0;
}
