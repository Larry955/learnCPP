#include<iostream>
using std::cerr;using std::cout;using std::endl;

#include<fstream>
using std::ifstream;

#include<cstring>
using std::string;

#include<stdexcept>
using std::runtime_error;

void process(ifstream &is)
{
    string s;
    while(is >> s){
        cout<<s<<endl;
    }
}


int main(int argc,char* argv[])
{

    //for each file passed to the program
    for(auto p = argv + 1;p != argc + argv; ++p){
        ifstream input(*p); //create input and open the file
        if(input)
            process(input);
        else
            cerr<<"couldn't open: " + string(*p);
    }//input goes out of scope and is destroyed on each iteration

    auto p = argv + 1,end = argv + argc;
    ifstream input;
    while(p != end){    //for each file passed to the program
        input.open(*p); //open the file,automatically clears the stream
        if(input)       //if the file is ok,process the input
            process(input);
        else
            cerr<<"could't open: " + string(*p);
        input.close();
        ++p;
    }
}
