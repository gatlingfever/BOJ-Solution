// Question : https://www.acmicpc.net/problem/11719

#include <iostream>
using namespace std;

int main()
{
	char cInput[10001] = {};
	int nCount = 0;
	do {
		cInput[nCount] = getchar();
		++nCount;
	} while (cInput[nCount - 1] != EOF);
	
	for (int i = 0; i < nCount - 1; ++i)
		cout << cInput[i];

	system("pause");
	return 0;
}