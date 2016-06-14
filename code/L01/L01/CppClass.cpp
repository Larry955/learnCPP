#include<iostream>
using namespace std;

class People{
public:
	void sayHello(){
		cout << "Hello!" << endl;
	}

};


int main()
{
	People p;
	p.sayHello();
	system("pause");
}