#include <iostream>

using namespace std;

class A
{
public:
	int a;
	double b;
	char* str;
	virtual void foo() = 0;

	void alert()
	{
		std::cout << "Attention!!!" << std::endl;
	}

};

class B : public A
{
public:
	char c;
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
	

	B b1;
	b1.alert();

	C c1;
	c1.a = 30;
	c1.b = 50;
	c1.foo();
}

void test_classes_pointers()
{
	A* pA;
	
	pA = new B();
	pA->foo();
}

int main()
{
	test_classes_pointers();
	return 0;
}