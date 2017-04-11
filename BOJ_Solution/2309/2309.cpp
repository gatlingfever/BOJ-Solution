// Question : https://www.acmicpc.net/problem/2309

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> VectorInput;
	int nTotalHeight = 0;
	for (int i = 0; i < 9; ++i)
	{
		int nTemp = 0;
		cin >> nTemp;
		VectorInput.push_back(nTemp);
		nTotalHeight += VectorInput[i];
	}

	for (int i = 0; i < 8; ++i)
	{
		for (int j = i + 1; j < 9; ++j)
			if (nTotalHeight - VectorInput[i] - VectorInput[j] == 100)
			{
				VectorInput[i] = 200;
				VectorInput[j] = 200;
			}
	}

	sort(VectorInput.begin(), VectorInput.end());
	for (int i = 0; i < 7; ++i)
		cout << VectorInput[i] << endl;

	system("pause");
	return 0;
}