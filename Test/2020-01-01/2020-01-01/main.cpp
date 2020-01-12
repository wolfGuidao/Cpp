#include<iostream>
using namespace std;

#if 0
class A
{
public:
	int _a;
};

class B:public A
{
public:
	int _b;
};


class C :public A
{
public:
	int _c;
};

class D:public B,public C
{
public:
	int _d;
};
#endif

#if 0
class A
{
public:
	int _a;
};

class B :virtual public A
{
public:
	int _b;
};


class C :virtual public A
{
public:
	int _c;
};

class D :public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	cout << sizeof(d) << endl;
	system("pause");
	return 0;
}

#endif

class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2" << endl;
	}
	
	int _b;
};

class Drived 
{
public:
	virtual void TestFunc3()
	{
		cout << "Drived::TestFunc3" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "Drived::TestFunc4" << endl;
	}

	int _a;
};

class Test:public Base,public Drived
{
	virtual void TestFunc1()
	{
		cout << "Test::TestFunc1" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Test::TestFunc3" << endl;
	}

	int _c;
};

int main()
{
	Test d;
	cout << sizeof(d) << endl;
	system("pause");
	return 0;
}