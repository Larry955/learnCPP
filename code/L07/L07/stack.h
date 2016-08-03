//定义链栈类stack的界面
//2016/6/28

typedef int element;		//定义一个别名，这样的话，如果要用其他类型的栈，只需要将int改为其他类型即可

struct Node			//链栈结点
{
	element data;		//存放链栈的元素
	Node *link;		//指向下一个结点的链
};
class stack{
public:
	//构造函数，设置栈顶为空指针
	stack();
	//析构函数，释放链栈结点占用的存储空间
	~stack();
	//判断链栈是否为空
	bool isEmpty();
	//返回当前栈顶的值
	//要求：栈非空
	element get_top();
	//将元素x入栈
	void push(element x);
	//将栈顶元素出栈
	//要求：栈非空
	void pop();
	//自顶向底打印链栈中的元素
	void print();
private:
	Node *top;

};