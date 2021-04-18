#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int i;
    char* time = (char *)malloc(10240 * sizeof(char));
    char* str = (char *)malloc(10240 * sizeof(char));
    char* str2 = (char *)malloc(10240 * sizeof(char));

    scanf("%s",time);
    for(i=0;i<2;i++)
        {
            str[i]=time[i];
        }
    str[i]='\0';

    for(i=8;i<10;i++)
    {
        str2[i-8]=time[i];
    }
    str2[i-8]='\0';

    if(strcmp(str2,"AM")==0)
    {
        if(time[0]=='1' && time[1]=='2')
        {
            time[0]='0';
            time[1]='0';
        }
        for(i=0;i<8;i++)
            printf("%c",time[i]);
    }
    else
    {
        if(time[0]=='1' && time[1]=='2')
        {
            time[0]='1';
            time[1]='2';
        }
        else if(time[1]=='8'||time[1]=='9')
            {
                time[0]='2';
                time[1]=time[1]-8;
            }
        else if(time[0]=='1' && time[1]=='1')
        {
            time[0]='2';
            time[1]=time[1]+2;
        }
        else
        {
            time[0]='1';
            time[1]=time[1]+2;
        }

        for(i=0;i<8;i++)
            printf("%c",time[i]);
    }
    return 0;
}
