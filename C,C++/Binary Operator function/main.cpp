#include <iostream>

using namespace std;

class A
{
    int x;
public:
    void get()
    {
        cin>>x;
    }
    A operator -(A a)
    {
        A temp;
        temp.x= x-a.x;
        return temp;
    }
    void out()
    {
        cout<<x;
    }
};
int main()
{
    A obj1,obj2,obj;
    obj1.get();
    obj2.get();
    obj=obj1 - obj2;
    obj.out();
    cout << "Hello world!" << endl;
    return 0;
}
