// Question : https://www.acmicpc.net/problem/7576

/*
Test Case 1; One Ripen Tomato
6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1
A : 8;

Test Case 2; Several Ripen Tomato
6 4
0 1 0 0 0 0
0 0 0 0 0 0
0 0 1 0 0 0
0 0 0 0 0 1
A : 3;

Test Case 3; All Ripen Tomato
6 4
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
A : 0;

Test Case 4; All Empty Space
6 4
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
A : 0;

Test Case 5; Long Lonely Journey
6 4
 0  0  0  0  0  0
 0 -1 -1 -1 -1  0
 0 -1 -1  0 -1  0
 0  0  0  0 -1  1
A : 15;

Test Case 6; Isolated I
6 4
0 -1 0 0 0 0
-1 0 0 0 0 0
0  0 0 0 0 0
0  0 0 0 0 1
A : -1;

Test Case 7; Isolated II
6 4
1 -1 0 0 0 0
-1 0 0 0 0 0
0  0 0 0 0 0
0  0 0 0 0 0
A : -1;

Test Case 8; Too Early
6 4
0  0  0  0  0  0
0 -1 -1 -1 -1  0
0 -1 -1  0 -1  0
0  0  0  0 -1  0
A : -1;
*/


#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int nWidth = 0;
	int nHeight = 0;
	cin >> nWidth >> nHeight;

	int** nTomatoBox = new int*[nHeight];
	for (int i = 0; i < nHeight; ++i)
		nTomatoBox[i] = new int[nWidth];

	queue<pair<int, int>> CheckingQueue;
	int nXadd[4] = { 1, 0, -1, 0 };
	int nYadd[4] = { 0, 1, 0, -1 };
	int nDate = 1;
	int nRipenTomato = 0;
	int nEmptySpace = 0;

	for (int i = 0; i < nHeight; ++i)
		for (int j = 0; j < nWidth; ++j)
		{
			cin >> nTomatoBox[i][j];
			switch (nTomatoBox[i][j])
			{
			case -1:
				++nEmptySpace;
				break;
			case 1:
				++nRipenTomato;
				CheckingQueue.push({ i, j });
				break;
			}
		}

	while (!CheckingQueue.empty())
	{
		int nXpos = CheckingQueue.front().second;
		int nYpos = CheckingQueue.front().first;
		CheckingQueue.pop();

		for (int i = 0; i < 4; ++i)
			if (nXpos + nXadd[i] >= 0 && nXpos + nXadd[i] < nWidth &&
				nYpos + nYadd[i] >= 0 && nYpos + nYadd[i] < nHeight &&
				!nTomatoBox[nYpos + nYadd[i]][nXpos + nXadd[i]])
			{
				nTomatoBox[nYpos + nYadd[i]][nXpos + nXadd[i]] = nTomatoBox[nYpos][nXpos] + 1;
				CheckingQueue.push({ nYpos + nYadd[i] , nXpos + nXadd[i] });
				++nRipenTomato;
				nDate = nDate > nTomatoBox[nYpos + nYadd[i]][nXpos + nXadd[i]] ? nDate : nTomatoBox[nYpos + nYadd[i]][nXpos + nXadd[i]];
			}
	}
	if (nEmptySpace == nWidth * nHeight)
		cout << 0;
	else if (nRipenTomato + nEmptySpace == nWidth * nHeight)
		cout << nDate - 1;
	else
		cout << -1;

	for (int i = 0; i < nHeight; ++i)
		delete[] nTomatoBox[i];
	delete[] nTomatoBox;

	system("pause");
	return 0;
}