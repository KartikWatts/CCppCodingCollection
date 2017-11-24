#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    int own_speed,sebi_guess,father_guess,test_cases,time_taken,distance,numb_marks,index;
    float speed,inacc1,inacc2;
    cin>>test_cases;
    while(test_cases--)
    {
        cin>>own_speed>>sebi_guess>>father_guess>>numb_marks>>time_taken;
        distance=numb_marks*50;
        speed=distance/(float)(time_taken);
        speed*=(18.0/5);
        speed+=own_speed;
        cout<<speed;
        inacc1=abs(speed-sebi_guess);
        inacc2=abs(speed-father_guess);
        cout<<inacc1<<endl<<inacc2<<endl;
        if(inacc1-inacc2<0){cout<<"SEBI"<<endl;}
        else if(inacc2-inacc1<0){cout<<"FATHER"<<endl;}
        else{cout<<"DRAW"<<endl;}
    }
    return 0;
}
