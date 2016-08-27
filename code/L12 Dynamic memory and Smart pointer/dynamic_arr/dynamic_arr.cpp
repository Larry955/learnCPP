#include<memory>
using std::shared_ptr; using std::unique_ptr;

int main()
{
	//up points to an array of ten uninitialized ints
	unique_ptr<int[]>up(new int[10]);	
	for (size_t i = 0; i != 10; ++i)
		up[i] = i;	//assign a new value to each of the elements
	up.release();	//automatically use delete[] to destroy its pointer

	//to use a shared_ptr we must supply a deleter
	shared_ptr<int>sp(new int[10], [](int *p){delete[] p; });
	//shared_ptr don't have subscript operator
	//and don't support pointer arithmetic 
	for (size_t i = 0; i = 10; ++i)
		*(sp.get() + i) = i;	//use get to get a build-in pointer
	sp.reset();
	getchar();		//use the lambda we supplied
					//that uses delete[] to free the array
}