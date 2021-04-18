#include <iostream>

using namespace std;

int main()
{
    int T,i,j;
    char str[400],temp;
    cin>>T;
    while(T--)
    {
        i=0;
        cin>>str;
        while(str[i]!='\0')
        {
            if(str[i]=='(')
            {
                for(j=i+1;str[j]!=')';j++)
                {
                    if(str[j]=='+'||str[j]=='-'||str[j]=='*'||str[j]=='/'||str[j]=='^')
                    {
                        temp=str[j];
                        str[j]=str[j+1];
                        str[j+1]=temp;
                    }
                }
            }
            for(j=i;str[j]!='\0';j++)
            {
            if(str[j]=='+'||str[j]=='-'||str[j]=='*'||str[j]=='/'||str[j]=='^')
                    {
                        temp=str[j];
                        str[j]=str[j+1];
                        str[j+1]=temp;
                    }
            }
            i++;
        }
        cout<<str;
    }
    return 0;
}
