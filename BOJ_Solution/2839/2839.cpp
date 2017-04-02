// Question : https://www.acmicpc.net/problem/2839

#include <iostream>
using namespace std;

int main()
{
	int nSum = 0;
	cin >> nSum;
	
	int n3Vinyl = 0;
	int n5Vinyl = 0;
	n5Vinyl = nSum / 5;

	while (n3Vinyl * 3 + n5Vinyl * 5 != nSum)
	{
		if(n5Vinyl < 0)
		{
			n5Vinyl = -1;
			n3Vinyl = 0;
			break;
		}
		else if ((nSum - n5Vinyl * 5) % 3 == 0)
			n3Vinyl = (nSum - n5Vinyl * 5) / 3;
		else if (nSum - n3Vinyl * 3 - n5Vinyl * 5 < 0)
			--n5Vinyl;
		else
			++n3Vinyl;
	}
	cout << n3Vinyl + n5Vinyl;
	system("pause");
	return 0;
}