#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<set>
using std::set;
#include<unordered_set>
using std::unordered_set;
int main()
{
	int n;
	cin >> n;
	int *sequences = new int[n];
	for (int i = 0; i != n; ++i){
		cin >> sequences[i];
	}
	for (int i = 0; i != n; ++i)
		cout << sequences[i] << " ";
	cout << endl;
	unordered_set<int>eraseDup;
	for (int i = n - 1; i >= 0; --i){
		if (eraseDup.find(sequences[i]) == eraseDup.end()){
			eraseDup.insert(sequences[i]);
		}
	}
	for (auto iter = eraseDup.rbegin(); iter != eraseDup.rend(); ++iter)
		cout << *iter << " ";
	cout << endl;
	delete[] sequences;
	system("pause");
}