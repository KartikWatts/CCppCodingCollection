#include <iostream>

using namespace std;

class C
{
    int id;
public:
    C(C &O)
    {
        id=O.id;
    }
    C()
    {
        id=20;
        cout<<id;
        id++;
    }
    void out()
    {
        cout<<id;
    }
};
int main()
{
    C obj1;
    C obj2(obj1);
    obj2.out();
    cout << "Hello world!" << endl;
    return 0;
}
