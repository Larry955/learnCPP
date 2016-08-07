#include<string>
using std::string;

#include<iostream>
using std::cout; using std::endl;

int main()
{
	string numbers("0123456789"), name("r2d2");
	//returns 1,the index of the first digit in name
	auto pos = name.find_first_of(numbers);
	if (pos != string::npos){
		cout << "found number at index: " << pos
			<< " element is " << name[pos] << endl;
	}
	else
		cout << "no number in: " << name << endl;

	pos = 0;
	//each iteration finds the next number in name
	while ((pos = name.find_first_of(numbers, pos))
		!= string::npos){
		cout << "found number at index: " << pos
			<< " element is " << name[pos] << endl;
		++pos;
	}

	string river("Mississipi");

	auto first_pos = river.find("is");	//returns 1
	auto last_pos = river.rfind("is");	//returns 4
	cout << "find returned " << first_pos
		<< " rfind returned " << last_pos << endl;

	string depts("01234p546");
	//returns 5,which is the index to the character 'p'
	pos = depts.find_first_not_of(numbers);
	cout << "first_not returned " << pos << endl;
	system("pause");
}