#include<iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	virtual void Func1() { cout << "AAA::Func1" << endl; }
	virtual void Func2() { cout << "AAA::Func2" << endl; }
};

class BBB : public AAA
{
private:
	int num2;
public:
	virtual void Func1() { cout << "BBB::Func1" << endl; }
	void Func3() { cout << "Func3" << endl; }
};

int main(void)
{
	AAA* aptr = new AAA();
	aptr->Func1();

	BBB* bptr = new BBB();
	bptr->Func1();

	aptr = bptr;
	aptr->Func1();
	aptr->AAA::Func1();
	
	
	return 0;

}

