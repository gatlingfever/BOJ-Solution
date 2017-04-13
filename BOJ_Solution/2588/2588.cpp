// Question : https://www.acmicpc.net/problem/2588

#include <iostream>
using namespace std;

int main()
{
	int nNum1 = 0;
	int nNum2[3] = {};
	cin >> nNum1;

	for (int i = 0; i < 3; ++i)
		scanf_s("%1d", &nNum2[i]);

	int nNum3 = nNum1 * nNum2[2];
	int nNum4 = nNum1 * nNum2[1];
	int nNum5 = nNum1 * nNum2[0];
	int nNum6 = nNum5 * 100 + nNum4 * 10 + nNum3;

	printf("%d\n", nNum3);
	printf("%d\n", nNum4);
	printf("%d\n", nNum5);
	printf("%d\n", nNum6);
	
	return 0;
}