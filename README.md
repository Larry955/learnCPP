## learnCPP


Just have a basic of C plus plus,the reason I upload my code is to learn to use github while learning C plus plus. 


================= **update on Sep,1,2016** ================

Before view this repo,the first thing you should know is that **the repo is not a project**.

As the file name tells,it just contains some cpp programs,most of which are from "C++ Primer,5th".

In order to make everything more clear,I am trying to update a list of programs which  are helpful and useful while I was learning.   


1) **/code/L06 - KMeans**.A course design of Data Structure which is implemented by cpp, it took me 1 week to finish it.But the final grade made me a little upset: I just got an "A-".Actually I think it deserves a higher rank.

Here is a brief introduction of K-Means algorithm: K-Means clustering is a method of vector quantization, it aims to partition n observations into k clusters in which each observation belongs to cluster with the nearset mean.

================= **update on Nov,15 2016** ================

2)**/code/L08 IO/fileIO**.A simple program which shows us how to pass parameters to the main() function.

3)**code/L11 Associative Container/word_transform**.A word-transform program.To get more details,go to the directory above,and you will find a help-document called "readme.md" there.

4)**code/L12 Dynamic memory and Smart pointer/TextQuery**.It is a practice of Class and Smart pointer from C++ primer.In this program,you can query a word from a file, the result returns all the lines the word appears and the content of the line.
Again,to get more details,go to the directory above and read the "READMD.md" document.

5)**code/L12 Dynamic memory and Smart pointer/StrBlob**.A Vector-like program.Class StrBlob implements most of the functions,Class StrBlobPtr manages the memorys(through smart pointer).Here is the list of the function it implements(assume that sb,sb2 are both StrBlob objects):

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


