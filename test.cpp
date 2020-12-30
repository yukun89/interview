#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
class B{
	int a;
};
class C{
	public:
	string a;
};
class D { static int a; };
class E { virtual void func(){}; };
class A {
public:
	int d;
	A()
	{
		std::cout << "A" << std::endl;
		d = 1;
	}
};

int main()
{
	std::cout << sizeof(A) << std::endl;
	std::cout << sizeof(B) << std::endl;
	std::cout << sizeof(C) << std::endl;
	std::cout << sizeof(D) << std::endl;
	std::cout << sizeof(E) << std::endl;
	C c;
	c.a="test";
	std::cout << sizeof(C) << std::endl;

	vector<A> arr;
	A a;
	arr.push_back(a);
	A &ref= arr[0];
	A* p= &arr[0];
	for (int i = 0; i<1000; i++) {
		arr.push_back(a);
	}
	std::cout << arr[0].d << std::endl;
	std::cout << ref.d << p->d;

	std::set<int> myset = {1, 3, 5, 7, 9};
	auto it5 = myset.find(5);
	myset.erase(5);
	it5++;
	std::cout << "it5++" << *it5 << std::endl;

	std::cout << *it5 << std::endl;
	for (int i = 0; i<=10 ; i+=2) {
		myset.insert(i);
	}
	std::cout << "it5:" << *it5 << std::endl;
	for (auto it = myset.begin(); it!= myset.end(); it++) {
		myset.erase(it);
	}
}
