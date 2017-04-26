// Question : https://www.acmicpc.net/problem/1065

#include <iostream>
using namespace std;

int main()
{
	bool bIsnotHnum[1001] = {};
	int nInput = 0;
	cin >> nInput;

	for (int i = 100; i < 1001; ++i)
	{
		int nHundred = i / 100;
		int nTen = i / 10 - nHundred * 10;
		int nRest = i % 10;

		if (nHundred - nTen != nTen - nRest)
			bIsnotHnum[i] = true;
	}
	int nAnswer = 0;
	for (int i = 1; i <= nInput; ++i)
		if (!bIsnotHnum[i])
			++nAnswer;
	cout << nAnswer;

	system("pause");

	return 0;
}