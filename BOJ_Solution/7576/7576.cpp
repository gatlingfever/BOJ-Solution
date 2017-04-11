// Question : https://www.acmicpc.net/problem/7576

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