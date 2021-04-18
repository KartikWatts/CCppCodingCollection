#include <iostream>

using namespace std;

int main()
{
    int T,S,SG,FG,D,Time;
    float dist,speed,x,y;
    cin>>T;
    if(T<1 || T>10000)
        return 1;
    while(T>0)
    {
        cin>>S>>SG>>FG>>D>>Time;
        if(S<0||S>130||SG<0||SG>300||FG<0||FG>300||D<1||D>30||T<1||T>300)
            {
                break;
            }
        dist=float(D)*50;
        dist=dist/1000;
        speed=(dist/Time)*3600;
        speed=speed+S;

        if(speed>300)
            break;
        x=SG-speed;
        if(x<0)
            x=x*(-1);
        y=FG-speed;
        if(y<0)
            y=y*(-1);

        if(x<y)
            cout<<"SEBI"<<endl;
        else if(x==y)
            cout<<"DRAW"<<endl;
        else
            cout<<"FATHER"<<endl;
        T--;
    }
    return 0;
}
