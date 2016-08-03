#include"stack.h"
#include<iostream>
using namespace std;
stack::stack()		
{
	top = NULL;		//将栈顶置为空
}

stack::~stack()
{
	Node *ptr;		//指定链栈结点的临时指针
	while (top){		//从顶至底释放链栈的结点
		ptr = top;		//先用ptr记录栈顶结点
		top = top->link;		//摘下栈顶结点，将下一结点作为新的栈顶
		delete ptr;		//释放原栈顶结点
	}
}

bool stack::isEmpty()
{
	if (!top)		//如果栈顶结点为空，返回真
		return true;
	return false;
}

element stack::get_top()
{
	if (isEmpty()){		//如果链栈为空，给出报错信息
		cout << "error: No element!\n";
		return -1;
	}
	else
		return top->data;		//如果非空，返回栈顶结点存放的元素
}

void stack::push(element x)
{
	Node *ptr = new Node;		//创建一个新结点
	if (ptr){		//如果成功分配了内存
		//在栈顶加入一个新的结点并连成链
		ptr->link = top;
		ptr->data = x;
		top = ptr;
	}
	else{		//内存分配失败（如：没有足够的内存）时给出错误信息
		cout << "error: No enough memory!\n";
		return;
	}
}

void stack::pop()
{
	Node *ptr;
	if (top){		//栈非空时才能出栈
		ptr = top;		//指向栈顶结点
		top = top->link;		//摘下原来的栈顶结点
		delete ptr;		//释放原来栈顶结点
	}
	else{		//栈为空时给出错误信息
		cout << "error: Pop element from empty stack!\n";
		return;
	}
}
void stack::print()
{
	Node *loop;
	loop = top;		//指向栈顶结点
	while (loop){		
		cout << loop->data<<" ";		//输出当前结点存放的数据
		loop = loop->link;		//指向下一结点
	}
	cout << "\n";
}