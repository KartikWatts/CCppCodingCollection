#include <iostream>

using namespace std;

class B;
class A
{
    int x;
    public:
    A(int a)
    {
        x=a;
    }
    void out()
    {
        cout<<x<<"\t";
    }
    friend void swap(A,B);
};

class B
{
    int y;
public:
    B(int b)
    {
        y=b;
    }
    void out()
    {
        cout<<y<<"\t";
    }
    friend void swap(A,B);
};

void swap(A a1, B b1)
{
    int temp;
    temp=a1.x;
    a1.x=b1.y;
    b1.y=temp;
    cout<<"After Swapping"<<endl<<"a= "<<a1.x<<"\tb= "<<b1.y;
}

int main()
{
    A a(108);
    B b(7);
    a.out();
    b.out();
    swap(a,b);
    return 0;
}
