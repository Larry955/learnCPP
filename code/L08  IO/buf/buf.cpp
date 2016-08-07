#include<iostream>
using std::endl;using std::flush;using std::ends;
using std::unitbuf;using std::nounitbuf;using std::cout;

int main()
{

    //writes hi and a newline,then flush the buffer
    cout<<"Hi"<<endl;

    //writes hi and flush the buffer,adds no data
    cout<<"Hi"<<flush;

    //writes hi ang a null,then flushes the buffer
    cout<<"Hi"<<ends;

    //cout<<unitbuf;  //all writes will be flush immediately

    //any output is flushed immediately,no buffering
    cout<<"first"<<"second"<<endl;

    cout<<nounitbuf;    //returns the normal buffering
}
