#include <iostream>
#include<string.h>
using namespace std;

int main()
{
    int T,act,rank,bonus,flag,laddu,months,severity,redeem;
    char origin[30],str[30];
    cin>>T;
    if(T<0 || T>100)
        return 1;
    while(T>0)
    {
        flag=0;
        laddu=0;
        months=0;
       cin>>act;
       if(act<0 || act>100)
            break;
       cin>>origin;
       if(strcmp(origin,"INDIAN")==0)
        redeem=200;
       else if(strcmp(origin,"NON_INDIAN")==0)
        redeem=400;
       while(act>0)
       {
           cin>>str;
           if(strcmp(str,"CONTEST_WON")==0)
           {
                cin>>rank;
                if(rank<1 || rank>5000)
                    {
                        flag=1;
                        act--;
                        break;
                    }
               if(rank>20)
                    bonus=0;
               else
                    bonus=20-rank;

               laddu=laddu+300+bonus;

           }

           if(strcmp(str,"TOP_CONTRIBUTOR")==0)
            laddu=laddu+300;

           if(strcmp(str,"BUG_FOUND")==0)
           {
               cin>>severity;
               if(severity<50 || severity>1000)
                {
                    flag=1;
                    break;
                }
               laddu=laddu+severity;
           }

           if(strcmp(str,"CONTEST_HOSTED")==0)
            laddu=laddu+50;

           act--;
       }
       if(flag==1)
        {
            T--;
            break;
        }
        while(laddu>=redeem)
        {
            laddu=laddu-redeem;
            months++;
        }
       cout<<months<<endl;
       T--;
    }
    return 0;
}
