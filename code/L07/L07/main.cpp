#include"stack.h"
#include<iostream>
using namespace std;

const int max_input = 5;		//�����û������������������ջ��Ԫ�صĸ���

int main()
{
	stack S;		//����һ�����͵���ջ
	element user_input;		
	int loop;
	for (loop = 0; loop != max_input; ++loop){
		cout << "Input NO." << loop + 1<<": ";		//��ʾ�ǵڼ�������
		cin >> user_input;		//�û�����Ԫ��
		S.push(user_input);		//����Ԫ����ջ
	}
	S.print();		//���ó�Ա������ӡ��ջ�е�Ԫ��
	//�Զ���ױ�������ӡ��ջ�е�Ԫ��
	for (loop = 0; loop != max_input; ++loop){		
		cout<<S.get_top()<<" ";		//��ӡ��ǰջ��Ԫ��
		S.pop();		//����ǰջ��Ԫ�س�ջ
	}
	system("pause");
}