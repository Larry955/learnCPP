#include"stack.h"
#include<iostream>
using namespace std;
stack::stack()		
{
	top = NULL;		//��ջ����Ϊ��
}

stack::~stack()
{
	Node *ptr;		//ָ����ջ������ʱָ��
	while (top){		//�Ӷ������ͷ���ջ�Ľ��
		ptr = top;		//����ptr��¼ջ�����
		top = top->link;		//ժ��ջ����㣬����һ�����Ϊ�µ�ջ��
		delete ptr;		//�ͷ�ԭջ�����
	}
}

bool stack::isEmpty()
{
	if (!top)		//���ջ�����Ϊ�գ�������
		return true;
	return false;
}

element stack::get_top()
{
	if (isEmpty()){		//�����ջΪ�գ�����������Ϣ
		cout << "error: No element!\n";
		return -1;
	}
	else
		return top->data;		//����ǿգ�����ջ������ŵ�Ԫ��
}

void stack::push(element x)
{
	Node *ptr = new Node;		//����һ���½��
	if (ptr){		//����ɹ��������ڴ�
		//��ջ������һ���µĽ�㲢������
		ptr->link = top;
		ptr->data = x;
		top = ptr;
	}
	else{		//�ڴ����ʧ�ܣ��磺û���㹻���ڴ棩ʱ����������Ϣ
		cout << "error: No enough memory!\n";
		return;
	}
}

void stack::pop()
{
	Node *ptr;
	if (top){		//ջ�ǿ�ʱ���ܳ�ջ
		ptr = top;		//ָ��ջ�����
		top = top->link;		//ժ��ԭ����ջ�����
		delete ptr;		//�ͷ�ԭ��ջ�����
	}
	else{		//ջΪ��ʱ����������Ϣ
		cout << "error: Pop element from empty stack!\n";
		return;
	}
}
void stack::print()
{
	Node *loop;
	loop = top;		//ָ��ջ�����
	while (loop){		
		cout << loop->data<<" ";		//�����ǰ����ŵ�����
		loop = loop->link;		//ָ����һ���
	}
	cout << "\n";
}