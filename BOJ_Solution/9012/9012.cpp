// Question : https://www.acmicpc.net/problem/9012

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int nTestCount = 0;
	cin >> nTestCount;
	
	bool* bAnswer = new bool[nTestCount];
	for (int i = 0; i < nTestCount; ++i)
	{
		char szInput[51] = "";
		stack<char> StackInput;
		cin >> szInput;
		for (int j = 0; j < 51; ++j)
		{
			switch (szInput[j])
			{
			case '(':
				StackInput.push(szInput[j]);
				break;
			case ')':
			{
				if (!StackInput.size())
				{
					bAnswer[i] = false;
					j = 100;
				}
				else
					StackInput.pop();
				break;
			}
			case '\0':
				bAnswer[i] = !StackInput.size();
				j = 100;
				break;
			}
		}
	}

	for (int i = 0; i < nTestCount; ++i)
	{
		if (bAnswer[i])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	system("pause");

	return 0;
}