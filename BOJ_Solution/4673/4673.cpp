// Question : https://www.acmicpc.net/problem/4673

#include <iostream>
using namespace std;

int GetNextNum(int nInput)
{
	int nCopyNum = nInput;
	while (nCopyNum)
	{
		nInput += nCopyNum % 10;
		nCopyNum /= 10;
	}
	return nInput;
}

int main()
{
	bool nSeries[10001] = {};
	for (int i = 1; i < 10001; ++i)
	{
		if(!nSeries[i])
			for (int j = GetNextNum(i); j < 10001;)
			{
				nSeries[j] = true;
				j = GetNextNum(j);
			}
	}
	for (int i = 1; i < 10001; ++i)
		if (!nSeries[i])
			cout << i << endl;
	system("pause");
	return 0;
}