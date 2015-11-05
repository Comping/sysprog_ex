#include <iostream>

using namespace std;

class A
{
public:
	int a;
	double b;
	char* str;
	virtual void foo() = 0;

    A(int a, double b)
    {
        this->a = a;
        this->b = b;
    }
	void alert()
	{
		std::cout << "Attention!!!" << std::endl;
	}

};

class B : public A
{
public:
	char c;
	B(int a, double b, char c)
        : A(a,b)
	{
	    this->c = c;

	}
	void foo()
	{
		cout << "Hello from B\n";
	}
	void bar()
	{
		cout << c;
	}
};

class C : public A
{
public:
	static const int sz = 3;
	int m_i[sz];

	C(int a, double b)
	 : A(a, b)
	 {}
	virtual void foo()
	{
		for (int i = 0; i < sz; ++i)
		{
			if (i > 0)
				cout << " ";
			cout << m_i[i];
		}
	}
};


void test_classes1()
{


	B b1(3,4.5, 'A');
	b1.alert();

	C c1(5, -1.4);
	c1.a = 30;
	c1.b = 50;
	c1.foo();
}

void test_classes_pointers()
{
	A* pA;

	pA = new B(4, 3.2, 'B');
	pA->foo();
}

int main()
{
	test_classes_pointers();
	return 0;
}
