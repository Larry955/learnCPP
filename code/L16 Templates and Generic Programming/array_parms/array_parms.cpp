#include<string>
using std::string;

#include<iostream>
using std::endl; using std::cout;

template<typename T,size_t n>
void print(T (&arr)[n])
{
	for (auto elem : arr)
		cout << elem << " ";
	cout << endl;
}

int main()
{
	int a1[] = { 1, 2, 3, 4, 6, 5 };
	int a2[] = { 3, 4, 5, 9, 7, 5, 7 };
	string a3[4] = { "hehe", "xixi", "ttt", "cpp" };

	print(a1);	//instantiates print(int (&arr)[6])
	print(a2);//instantiates print(int (&arr[7]))
	print(a3);//instantiates print(string (&arr)[4])

	system("pause");
}