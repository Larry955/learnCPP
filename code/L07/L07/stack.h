//������ջ��stack�Ľ���
//2016/6/28

typedef int element;		//����һ�������������Ļ������Ҫ���������͵�ջ��ֻ��Ҫ��int��Ϊ�������ͼ���

struct Node			//��ջ���
{
	element data;		//�����ջ��Ԫ��
	Node *link;		//ָ����һ��������
};
class stack{
public:
	//���캯��������ջ��Ϊ��ָ��
	stack();
	//�����������ͷ���ջ���ռ�õĴ洢�ռ�
	~stack();
	//�ж���ջ�Ƿ�Ϊ��
	bool isEmpty();
	//���ص�ǰջ����ֵ
	//Ҫ��ջ�ǿ�
	element get_top();
	//��Ԫ��x��ջ
	void push(element x);
	//��ջ��Ԫ�س�ջ
	//Ҫ��ջ�ǿ�
	void pop();
	//�Զ���״�ӡ��ջ�е�Ԫ��
	void print();
private:
	Node *top;

};