## learnCPP


Just have a basic of C plus plus,the reason I upload my code is to learn to use github while learning C plus plus. 


================= **update on Sep,1,2016** ================

Before view this repo,the first thing you should know is that **the repo is not a project**.

As the file name tells,it just contains some cpp programs,most of which are from "C++ Primer,5th".

In order to make everything more clear,I am trying to update a list of programs which  are helpful and useful while I was learning.   


1) **/code/L06 - KMeans**.A course design of Data Structure which is implemented by cpp, it took me 1 week to finish it.But the final grade made me a little upset: I just got an "A-".Actually I think it deserves a higher rank: )

Here is a brief introduction of K-Means algorithm: K-Means clustering is a method of vector quantization, it aims to partition n observations into k clusters in which each observation belongs to cluster with the nearset mean.

================= **update on Nov,15 2016** ================

2)**/code/L08 IO/fileIO**.A simple program which shows us how to pass parameters to the main() function.

3)**code/L11 Associative Container/word_transform**.A word-transform program.To get more details,go to the directory above,and you will find a help-document called "readme.md" there.

4)**code/L12 Dynamic memory and Smart pointer/TextQuery**.It is a practice of Class and Smart pointer from C++ primer.In this program,you can query a word from a file, the result returns all the lines the word appears and the content of the line.
Again,to get more details,go to the directory above and read the "READMD.md" document.

5)**code/L12 Dynamic memory and Smart pointer/StrBlob**.A Vector-like program.Class StrBlob implements most of the functions,Class StrBlobPtr manages the memorys(through smart pointer).Here is a list of the function it implements(assume that sb,sb2 are both StrBlob objects):

- sb = {"a","bc","ddd"};//initializer_list
- sb.size(); //returns the size of str
- sb.empty();//check that if str is empty
- sb.push_back("larry"); //push "larry" into sb
- sb.pop_back(); //pop the top element
- sb2 = sb; //assignment
- sb.front(); //returns the first element of sb
- sb.back();  //returns the last element of sb
- eq(sb,sb1); //returns true if sb and sb1 are equal
- neq(sb,sb1);  //returns false if not equal

================= **update on Mar，12 2017** ================

6)**code/L13 Copy Control/Folder/**.A program which simulates a Folder-Manager.In this program,a Folder can "store" many messages,and a message can be stored in different folders.List below shows some functions it implements:
```
Message m1("content");
Folder f1,f2;
m1.save(f1); //m1 is saved in Folder 'f1'
m1.save(f2);  //m1 is saved in Folder 'f2'
f1.save(Message("content2")); //Folder f1 saves a message named 'content2'
```
7)**code/L13 Copy Control/String**.A string-like program,here is the operations it supports:
- String s(String("larry"));  //copy constructor
- String s1("Larry"); //constructor String(const char*)
- String s2 = s1;   //copy assignment operator
- String s2(std::move(s1)); //move constructor
- String s2 = std::move(s1);  //move assignment operator
- String s3(5,'n');  //constructor String(size_t,char) , s3 = 'nnnnn'
- s3 = "Larry"; //String& operator=(const char*);
- s3 = 'L'; //String& operator=(char);

8)**code/L14 Overloaded operations and Conversions/Sales**.A sales_book program.In this program,we overload some operators such as "+","-","=","==","!=","+=","<<",">>"...

Some interesting implements needs to be shown here.
we overload "!=" operator through "==" operator,
we overload "+" operator through "+=" operator

...

Another case we need to be aware of is "self_assignment",which should be noticed to avoid memeory-leak(perhaps...)

**self-assigment**:
```
Sales_data book;
book = book;
```

9)**code/L15 Object-Oriented Programming/Basket_main/**.
In the program,we implement inheritance.class Quote is the base class,while Disc_Quote,Bulk_Quote,Lim_Quote are classes inherited by Quote.
To implement dynamic-binding,we use **virtual-function**.
To avoid memory-leak,we use **virtual destructor**.
To manage memory by an "elegant way",we use **smart pointer**.

10)**code/L15 Object-Oriented Programming/wordQueryTest**. A program that could read a file to search speicfied words.

11)**code/L16 Templates and Generic Programming/Vector**.A **vector-like** program implemented through template.Here are the operations it supports:
- Vector<string> handsome; //template
- v.push_back("larry"); //push larry into handsome
- v.size();   //return the size of v,which shows the number of elements it holds 
- v.capacity(); //return the capacity of v,it's always greater or equal than v.size(),if v.size() equals to v.capacity(),than reallocate v
- v = {"Larry","is","handsome"};  //implemented by initializer_list
- Vector<string> handsome1(handsome);  //copy-constructor
- Vector<string> handome1 = handsome;  //copy assignment operator
- v[0];   //implemented by overload '[]' operator
 
