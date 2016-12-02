#include<iostream>
#include<cstdio>//for EOF

int main()
{
	int ch;	//use an int,not a char to hold the return from get()

	//loop to read and write all the data in the input
	while ((ch = std::cin.get()) != EOF)	//EOF:end-of-file		equals to -1
		std::cout.put(ch);	//the loop won't exit until we press Ctrl+Z in Windows
	std::cout << std::endl;
	system("pause");
}