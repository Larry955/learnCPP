
#include"Blob.h"
#include<iterator>
#include<list>
using namespace std;

int main()
{
	Blob<int>ia;	//an empty Blob<int>
	Blob<int>ia2 = { 1, 2, 3, 4 };	//Blob(initializer_list<int>)
	vector<int>v(10, 0);	//ten	elements initialized to 0
	Blob<int>ia3(v.begin(), v.end());	//Blob(It b,It e)
	cout << ia << "\n" << ia2 << "\n" << ia3 << endl;
	
	//these definitions instantiate two distinct	Blob types
	Blob<string>names;
	Blob<double>prices;

	//instantiates Blob<string> class and its
	//initializer_list<const char*> constructor
	Blob<string>articles = { "a", "an", "the" };

	//instantiates Blob<int>
	Blob<int>squares = { 1, 2, 3, 4, 5, 6 };
	cout << squares << endl;
	for (size_t i = 0; i != squares.size(); ++i){
		squares[i] = i * i;
	}
	cout << squares << endl;

	//instantiates the Blob<int> constructor that has
	//two vector<long>::iterator parameters
	vector<long>v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Blob<int>a1(v1.begin(), v1.end());	//copy from a vector
	cout << "a1: " << a1 << endl;

	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Blob<int>a2(begin(arr), end(arr));	//copy from a array
	cout << "a2: " << a2 << endl;

	list<int>li(10, 0);	//10 elements all zeros
	Blob<int>zeros(li.begin(), li.end());	//copy from a list
	cout << "zeros: " << zeros << endl;
	
	a1.swap(zeros);
	cout << "a1: " << a1 << "\nzeros: " << zeros << endl;

	list<const char*>w = { "larry", "king", "is", "so", "handsome" };
	//instantiates the Blob<string> class and Blob<string>
	//constructor that has two list<const char*> iterator parameters
	Blob<string>w2(w.begin(), w.end());	//copy from a list 
	system("pause");
}