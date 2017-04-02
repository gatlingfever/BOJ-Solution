// Question : https://www.acmicpc.net/problem/2750

#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> List;
	int nCount = 0;
	cin >> nCount;
	for (int i = 0; i < nCount; ++i)
	{
		int nTemp = 0;
		cin >> nTemp;
		List.push_back(nTemp);
	}
	List.sort();
	for (int i : List)
		cout << i << endl;
	system("pause");
	return 0;
}