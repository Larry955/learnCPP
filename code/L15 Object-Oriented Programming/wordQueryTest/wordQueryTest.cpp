#include"Query.h"
#include"TextQuery.h"
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iostream>
#include<fstream>
#include<cctype>
#include<cstring>
#include<stdlib.h>
using std::string;
using std::vector;
using std::set;
using std::map;
using std::ostream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;

int main(int argc, char **argv)
{
	TextQuery file = get_file(argc, argv);

	//iterate with the user:prompt for a word to find and print results
	do{
		string sought;
		if (!get_word(sought))break;

		//find all the occurences of the requested string
		//define synoym for the line_no set
		Query name(sought);
		const auto results = name.eval(file);
		cout << "\nExecuting search for: " << name << endl;
		cout << results << endl;
	} while (true);	//the exit is inside the loop
	system("pause");
}
