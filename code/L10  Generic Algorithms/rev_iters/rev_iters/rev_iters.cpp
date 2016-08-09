#include<vector>
using std::vector;

#include<iostream>
using std::cout; using std::endl;

int main()
{
	vector<int>vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	
	//reverse iterator of vector from back to front
	for (auto iter = vec.crbegin();		//binds iter to the last element  
			  iter != vec.crend();		//one before the first element
			  ++iter)					//decrements the iterators one element
		cout << *iter << " ";			//prints 9...0
	cout << endl;
	getchar();
}