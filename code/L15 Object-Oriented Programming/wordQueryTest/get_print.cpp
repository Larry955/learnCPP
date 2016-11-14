#include"Query.h"
#include"TextQuery.h"

#include<string>
using std::string;

#include<iostream>
using std::cout; using std::cin; 
using std::cerr; using std::endl;

#include<fstream>
using std::ifstream;

#include<stdexcept>
using std::runtime_error;

//these functions are declared in Query.h

TextQuery get_file(int argc, char **argv)
{
	ifstream infile;
	if (argc == 2)
		infile.open(argv[1]);
	if (!infile)
		throw runtime_error("No input file!");

	return TextQuery(infile);	//builds file map
}

bool get_word(string &s1)
{
	cout << "enter a word to search for,or q to quit: ";
	cin >> s1;
	if (!cin || s1 == "q")return false;
	else return true;
}

bool get_words(string &s1, string &s2)
{
	//iterate with the user: prompt for a word to find and print the results
	cout << "enter two word to search for,or q to quit: ";
	cin >> s1;
	//stop if hit eof or a "q" is pressed
	if (!cin || s1 == "q")return false;
	cin >> s2;
	return true;
}

