#include<stack>
using std::stack;

#include<iostream>
using std::cout; using std::endl;

int main()
{
	stack<int>intStack;		//empty stack
		
	//fill up the stack
	for (size_t ix = 0; ix != 10; ++ix)
		intStack.push(ix);		//intStack holds 0...9 inclusive

	//while there are still values in intStack
	while (!intStack.empty()){
		int value = intStack.top();
		//code that uses value
		cout << value << " ";
		intStack.pop();		//pop the top element,and repeat
	}
	getchar();

}