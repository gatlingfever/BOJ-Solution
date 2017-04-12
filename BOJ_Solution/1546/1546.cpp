// Question : https://www.acmicpc.net/problem/1546

#include <iostream>
using namespace std;

int main()
{
	int nScore[1001] = {};
	int nCount = 0;
	float fAvr = 0.f;
	cin >> nCount;
	
	int nSum = 0;
	int nMax = 0;
	for (int i = 0; i < nCount; ++i)
	{
		cin >> nScore[i];
		nSum += nScore[i];
		nMax = nMax > nScore[i] ? nMax : nScore[i];
	}
	fAvr = static_cast<float>(nSum) / static_cast<float>(nMax) * 100 / nCount;
	printf("%.2f", fAvr);
	
	system("pause");
	return 0;
}