#include<iostream>
using std::cout;using std::cin; using std::endl;

#include<cstring>
using std::string;

#include<list>
using std::list;

int main()
{
    list<string>lst;

    string word;
    auto iter = lst.begin();
    while(cin>>word)
        iter = lst.insert(iter,word);   //作用等同于push_front()
    auto ip = lst.begin(),id = lst.end();
    while(ip != id){
        cout<<*ip++<<endl;
    }

    list<string>lst1 = {"Hello","Larry","King"};
    lst1.insert(lst1.end(),{"I","Love","You"});
    auto ip1 = lst1.begin(),id1 = lst1.end();
    while(ip1 != id1){
        cout<<*ip1++<<endl;
    }
}
