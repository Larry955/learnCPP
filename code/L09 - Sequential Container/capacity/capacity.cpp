#include<vector>
using std::vector;

#include<iostream>
using std::cout;using std::endl;


int main()
{
    vector<int>ivec;

    //size should be zero,capacity is implementation defined
    cout<<"ivec: size: "<<ivec.size()
        <<" capacity: "<<ivec.capacity()<<endl;

    //give ivec 24 elements
    for(vector<int>::size_type ix = 0; ix != 24; ++ix)
        ivec.push_back(ix);
    //size should be 24, capacity will be >= 24 and is implementation defined
    cout<<"ivec: size: "<<ivec.size()
        <<" capacity: "<<ivec.capacity()<<endl;

    ivec.reserve(50);   //set capacity at least 50,might be more
    //size should be 24,and capacity will be >= 50 and is implementation defined
    cout<<"ivec: size: "<<ivec.size()
        <<" capacity: "<<ivec.capacity()<<endl;

    //add elements to use up the excess capacity
    while(ivec.size() != ivec.capacity())
        ivec.push_back(0);
    //capacity should be unchanged and size and capacity are equal now
    cout<<"ivec: size: "<<ivec.size()
        <<" capacity: "<<ivec.capacity()<<endl;

    //add one more element
    ivec.push_back(42);
    //size should be 51,and capacity will be >= 51 and is implementation defined
    cout<<"ivec: size: "<<ivec.size()
        <<" capacity: "<<ivec.capacity()<<endl;

    ivec.shrink_to_fit();   //ask for the memory to be returned

    //size should be unchanged ,capacity is implementation defined
    cout<<"ivec: size: "<<ivec.size()
        <<" capacity: "<<ivec.capacity()<<endl;
}
