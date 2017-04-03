// Question : https://www.acmicpc.net/problem/7576

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int nWidth = 0;
	int nHeight = 0;
	int8_t cTomatoBox[1000][1000] = {};
	int nDate = 0;
	int nXadd[4] = { 1, 0, -1, 0 };
	int nYadd[4] = { 0,1, 0, -1 };

	int nRipenTomato = 0;
	int nEmptySpace = 0;
	
	cin >> nWidth >> nHeight;
	int nTotalSpace = nWidth * nHeight;

	for (int i = 0; i < nHeight; ++i)
		for (int j = 0; j < nWidth; ++j)
			scanf_s("%hhd", &cTomatoBox[i][j]);

	queue<pair<int, int>> CheckingQueue;
	do
	{
		++nDate;
		nEmptySpace = 0;
		for (int i = 0; i < nHeight; ++i)
			for (int j = 0; j < nWidth; ++j)
			{
				if (cTomatoBox[i][j] == nDate)
				{
					CheckingQueue.push({ i, j });
					++nRipenTomato;
				}
				else if (cTomatoBox[i][j] == -1)
					++nEmptySpace;
			}

		if (nEmptySpace == nTotalSpace)
		{
			nDate = 1;
			break;
		}
		if (!nRipenTomato)
		{
			nDate = 0;
			break;
		}
		if (nEmptySpace + nRipenTomato == nTotalSpace)
			break;
		if (!CheckingQueue.size())
		{
			nDate = 0;
			break;
		}


		while (CheckingQueue.size())
		{
			int nXpos = CheckingQueue.front().second;
			int nYpos = CheckingQueue.front().first;
			CheckingQueue.pop();

			for (int i = 0; i < 4; ++i)
			{
				if (nXpos + nXadd[i] >= 0 && nXpos + nXadd[i] < nWidth &&
					nYpos + nYadd[i] >= 0 && nYpos + nYadd[i] < nHeight &&
					!cTomatoBox[nYpos + nYadd[i]][nXpos + nXadd[i]])
					cTomatoBox[nYpos + nYadd[i]][nXpos + nXadd[i]] = nDate + 1;
			}
		}
	} while (true);

	cout << nDate - 1;

	system("pause");
	return 0;
}