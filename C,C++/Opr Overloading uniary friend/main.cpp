#include <iostream>

using namespace std;

class A
{
    int x,y;
public:
    A(int a,int b)
    {
        x=a;
        y=b;
    }
    void out()
    {
        cout<<x<<endl;
        cout<<y<<endl;
    }
    friend void operator -(A &a)
    {
        a.x=-a.x;
        a.y=-a.y;
    }
};
int main()
{
    A aa(12,45);
    aa.out();
    -aa;
    aa.out();
    cout << "Hello world!" << endl;
    return 0;
}
