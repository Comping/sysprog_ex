#include <iostream>

using namespace std;

class A
{
    int a;
public:
    A(int a)
    {
        this->a = a;
    }
};

class B : public A {
    int b;
public:
    B(int a, int b)
     : A(a)
    {
        this->b = b;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
