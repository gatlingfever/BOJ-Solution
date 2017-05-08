// Question : https://www.acmicpc.net/problem/1157

#include <iostream>
using namespace std;

int main()
{
	int nCounter[26] = {};
	char* szInput = new char[1000000];
	cin >> szInput;

	for (int i = 0; szInput[i] != '\0'; ++i)
	{
		if (szInput[i] >= 'A' && szInput[i] <= 'Z')
			++nCounter[szInput[i] - 'A'];
		else if(szInput[i] >= 'a' && szInput[i] <= 'z')
			++nCounter[szInput[i] - 'a'];
	}

	int nIndex = 0;
	int nMax = 0;
	bool bisDoubled = false;
	for (int i = 0; i < 26; ++i)
	{
		if (nCounter[i] > nMax)
		{
			nIndex = i;
			nMax = nCounter[i];
			bisDoubled = false;
		}
		else if (nCounter[i] == nMax)
			bisDoubled = true;
	}

	if (bisDoubled)
		cout << "?";
	else
		printf("%c", nIndex + 'A');

	delete[] szInput;

	system("pause");

	return 0;
}