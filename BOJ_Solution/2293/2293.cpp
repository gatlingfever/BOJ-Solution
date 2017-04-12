// Question : https://www.acmicpc.net/problem/2293

#include <iostream>
using namespace std;

int main()
{
	int nCoinCount = 0;
	int nAimNum = 0;
	int nAnswer[10001] = {};
	int nPrice[100] = {};
	
	cin >> nCoinCount >> nAimNum;

	for (int i = 0; i < nCoinCount; ++i)
		cin >> nPrice[i];

	nAnswer[0] = 1;
	for (int i = 0; i < nCoinCount; ++i)
		for (int j = nPrice[i]; j <= nAimNum; ++j)
			nAnswer[j] += nAnswer[j - nPrice[i]];
	cout << nAnswer[nAimNum];

	system("pause");
	return 0;
}