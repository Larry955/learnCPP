#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;
int main()
{
	ofstream of("J:\\data.txt");   //д�뵽ָ��λ��
	of << "Larry,why are you so cool?\n";
	of.close();	//�ر��ļ���
	ifstream inf("data.txt");	//�����ļ���
	stringbuf sb;	//��������������sstream��
	inf >> &sb;		//���ļ�����sb��
	cout << sb.str() << endl;	//ͨ��sb����ȡ�ļ��е���������
	system("pause");
}