/*************************************************************************
    > File Name: main.cpp
    > Author: lancer
 ************************************************************************/

#include<iostream>

#include"smart_pointer.h"
using namespace std;

class A
{
public:
    int i;
    A(int n):i(n) { };
    ~A() { cout << i << " " << "destructed" << endl; }
};

int main()
{
	A* x = new A(777);

	shared_pointer<A> test(x);

	cout << "test引用计数： " << test.useCount() <<endl;
    A* y=new A(888);
    shared_pointer<A> test2(y);
    cout << "test2引用计数： " << test2.useCount() <<endl;

    shared_pointer<A> test3(test2);
    cout << "test2引用计数： " << test2.useCount() <<endl;
    cout << "test3引用计数： " << test3.useCount() <<endl;

    test3 = test;
    cout << "test引用计数： " << test.useCount() <<endl;
    cout << "test2引用计数： " << test2.useCount()<< endl;
    cout << "test3引用计数： " << test3.useCount() <<endl;
	
	test2 = test3;
    cout << "test引用计数： " << test.useCount() <<endl;
    cout << "test2引用计数： " << test2.useCount() <<endl;
    cout << "test3引用计数： " << test3.useCount() <<endl;
	return 0;
}

