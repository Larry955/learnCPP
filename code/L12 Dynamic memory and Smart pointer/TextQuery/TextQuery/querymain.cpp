#include<string>
using std::string;

#include<fstream>
using std::ifstream;

#include<iostream>
using std::endl; using std::cout; 
using std::cin; using std::cerr;

#include<cstdlib>	//for EXIT_FAILURE

//#include"make_plural.h"
#include"TextQuery.h"

void runQueries(ifstream &infile)
{
	//infile is an ifstream that is the file we want to query
	TextQuery tq(infile);	//store the file and build the query map
	//iterate with the user: promote for a word to find and print the result
	while (true){
		cout << "enter word to look for,or q to quit: ";
		string s;
		//stop if we hit end_of_file on the input or if a "q" is entered
		if (!(cin >> s) || s == "q")break;
		else
			//run the query and print the results
			print(cout, tq.query(s)) << endl;
	}
}

//prigram takes single argument specifying the file to query
int main(int argc, char **argv)
{
	//open the file from which user will query words
	ifstream infile;
	//open returns void, so we use comma operator 
	//to check the state of infile after the open
	if (argc < 2 || !(infile.open(argv[1]), infile)){
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	runQueries(infile);
	getchar();
}