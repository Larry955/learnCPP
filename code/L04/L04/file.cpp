#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;
int main()
{
	ofstream of("J:\\data.txt");   //写入到指定位置
	of << "Larry,why are you so cool?\n";
	of.close();	//关闭文件流
	ifstream inf("data.txt");	//读入文件流
	stringbuf sb;	//缓冲流，包含在sstream中
	inf >> &sb;		//将文件读入sb中
	cout << sb.str() << endl;	//通过sb来获取文件中的所有内容
	system("pause");
}