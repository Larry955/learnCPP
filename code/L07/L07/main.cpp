#include"stack.h"
#include<iostream>
using namespace std;

const int max_input = 5;		//定义用户最大的输入次数，即链栈中元素的个数

int main()
{
	stack S;		//声明一个整型的链栈
	element user_input;		
	int loop;
	for (loop = 0; loop != max_input; ++loop){
		cout << "Input NO." << loop + 1<<": ";		//显示是第几次输入
		cin >> user_input;		//用户输入元素
		S.push(user_input);		//将该元素入栈
	}
	S.print();		//调用成员函数打印链栈中的元素
	//自顶向底遍历并打印链栈中的元素
	for (loop = 0; loop != max_input; ++loop){		
		cout<<S.get_top()<<" ";		//打印当前栈顶元素
		S.pop();		//将当前栈顶元素出栈
	}
	system("pause");
}