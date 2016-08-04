#include<algorithm>
using std::find;

#include<list>
using std::list;

#include<forward_list>
using std::forward_list;

#include<vector>
using std::vector;

#include<cstring>
using std::string;

#include<iostream>
using std::cout;using std::endl;

int main()
{
    //lst has 10 elements 0 ... 9 in value
    list<int>lst = {0,1,2,3,4,5,6,7,8,9};

    //print inital values in lst
    cout<<"initial list: ";
    for(auto it :lst)
        cout<<it<<" ";
    cout<<endl;

    //erase odd elements in lst
    auto it = lst.begin();
    while(it != lst.end()){
        if(*it % 2 != 0)        //if the element is odd,
            it = lst.erase(it);    //erase the element
        else
            ++it;
    }

    //print the current contents of lst
    cout<<"after erase the odd elements from lst: ";
    for(auto it :lst)
        cout<<it<<" ";
    cout<<endl;

    //repeat the same action but on a forward_list
    forward_list<int>flst = {0,1,2,3,4,5,6,7,8,9};
    auto prev = flst.before_begin();     //element "off the start" of flst
    auto curr = flst.begin();       //denotes the first element of flst
    while(curr != flst.end()){      //while there are still elements
        if(*curr & 2)               //if the element is odd
            curr = flst.erase_after(prev);//erase it and remove
        else{
            prev = curr;            //move the iterators to denotes the next
            ++curr;                 //element and one of the next element
        }
    }

    //print the current elements of flst
    for(auto it :flst){
        cout<<it<<" ";
    }
    cout<<endl;
}
