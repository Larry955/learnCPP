This project implements a **text-query** program.

In this program,We read a file from main(which is passed the by cmd) which contains an article or news,if you run it successfully,
you may see some sentences like follows:

"**Enter the word you need to query, or q to quit**".

Then input a word(such as "the"),we probably see the answer like this:

**the occurs 10 times:**

**(line 2): I don't like the apple**

**(line 11): Enter the word**

and so on.

The program won't quit unless your input is invalid or a "q" is pressed.

if you want to run the project,please follow these steps:
1)**download** the whole project to your computer;

2)**open cmd**,use "cd" command to get access to  the directory that stores the project,for example:
cd G:\C++projects

3)**compile these files**,the command(in Windows) is:

**g++ make_plural.h QueryResult.h TextQuery.h TextQuery.cpp querymain.cpp**

If you need to support C+ +11 standard,please add "-std=c+ +0x" afterwards,just like this:

**g++ make_plural.h QueryResult.h TextQuery.h TextQuery.cpp querymain.cpp -std=c++0x**

4)pass parameters to main.After step 3, the system will automatically create an "a.exe" for us.So if we want to pass parameters,
what we need to input is:

**a data.txt**

Note: data.txt is the parameter we need to pass,it's a file that contains an article,which is from <A Tale of Two Cities>:Chapter1 - The Period.

5)press "Enter", follow the instructions,and you will get the answer.
