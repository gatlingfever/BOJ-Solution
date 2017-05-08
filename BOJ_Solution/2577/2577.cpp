// Question : https://www.acmicpc.net/problem/2577

#include <iostream>
using namespace std;

int main()
{
	int nInput[3] = {};
	int nAnswer[10] = {};
	int nMultiplied = 0;

	for (int& i : nInput)
		cin >> i;

	nMultiplied = nInput[0] * nInput[1] * nInput[2];

	int nTemp = 0;

	while (nMultiplied)
	{
		nTemp = nMultiplied % 10;
		++nAnswer[nTemp];
		nMultiplied /= 10;
	}

	for (int i : nAnswer)
		cout << i << endl;

	system("pause");

	return 0;
}