#include"Query.h"
#include"TextQuery.h"
#include<iostream>
using std::endl; using std::cout; 
using std::cin; using std::cerr;

#include<stdexcept>
using std::runtime_error;

TextQuery get_file(int argv, char **argc)
{
	//get a file to read from which user will query words
	ifstream infile;
	if (argv == 2)
		infile.open(argc[1]);
	try{
		if (!infile)
			throw runtime_error("No input file!");
	}
	catch (runtime_error e){
		cerr << e.what() << "please input the file." << endl;
	}
	return TextQuery(infile);	//builds query map
}

bool get_word(string &s)
{
	cout << "enter a word to search for,or q to quit: ";
	cin >> s;
	if (!cin || s == "q")return false;
	else return true;
}

bool get_words(string &s1, string &s2)
{
	cout << "enter two words to earch for,or q to quit: ";
	cin >> s1;
	if (!cin || s1 == "q")return false;
	cin >> s2;
    return true;
}