#include<iostream>
#include<set>
#include<time.h>
using namespace std;
int main()
{
	clock_t startTime = clock();
	int w, x, y, z;
	int p, q;
	set<int>s;
	cin >> w >> x >> y >> z;
	if (x < y)
		s.insert(0);
	int tag = 0;
	for (int i = w; i <= x; ++i){
		for (p = i; p <= x; ++p){
			for (int j = y; j <= z; ++j){
				if (x < y)
					break;
				if (p < j){
					if (tag == 0)
						s.insert(0);
					tag = 1;
					break;
				}
				for (q = j; q <= z; ++q){ 
					if (s.find(p / q) == s.end())
						s.insert(p / q);
					else
						continue;
				}
			}
		}
	}
	clock_t endTime = clock();
	for (auto iter = s.cbegin(); iter != s.cend(); ++iter)
		cout << *iter << " ";
	cout << "\nsize: " << s.size() << endl;
	cout << "Running time: " << 
		static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << " ms";
	cout << endl;
	system("pause");
}