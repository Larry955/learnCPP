#include"Blob.h"

typedef BlobPtr<string> StrBlob;

template<typename T>using twin = pair < T, T > ;
template<typename T>using partNo = pair < T, unsigned > ;

int main()
{
	twin<string> author("Laryr", "King");
	twin<int>win(2, 42);
	typedef string Vechicle;
	partNo<Vechicle>car ("volov", 42);
	 
	Blob<int> bi = { 1, 2, 3, 4, 5, 6 };
 	cout << bi << endl;
	cout << bi.front() << " " << bi.back() << " " << bi.at(2) << endl;

	Blob<string>s;	//empty Blob
	cout << s.empty() << endl;
	//cout << s.front() << endl;	//throw out_of_range exception
	s.push_back("Hello");
	s.push_back("Larry");
	s.push_back("King");
	cout << "s has " << s.size() << 
		" elements: " << s << endl;

	//Pointer
	Blob<string> *sp = &s;
	sp->pop_back();
	cout << "s now has " << s.size() <<
		" elements: " << s << endl;

	system("pause");
}