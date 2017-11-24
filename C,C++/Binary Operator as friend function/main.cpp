#include <iostream>

using namespace std;

class A
{
    int x,y;
    public:
        void get()
        {
            cin>>x>>y;
        }

        friend A operator *(A a1,A a2)
        {
            A a;
            a.x=a1.x * a2.x;
            a.y=a1.y * a2.y;
            return a;
        }
        void out()
        {
            cout<<x<<endl<<y;
        }
};
int main()
{
    A o1,o2,o3;
    o1.get();
    o2.get();
    o3=o1*o2;
    o3.out();
    return 0;
}
