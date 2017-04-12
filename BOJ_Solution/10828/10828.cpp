// Question : https://www.acmicpc.net/problem/10828

#include <iostream>
#include <string.h>
using namespace std;

class CStack
{
public:
	CStack()
		: m_arData{}
		, m_nSize(0)
	{};
	~CStack() {};

private:
	int m_arData[10000];
	int m_nSize;

public:
	void push(int nData)
	{
		m_arData[m_nSize] = nData;
		++m_nSize;
	}
	int pop()
	{
		if (!m_nSize)
			return -1;
		--m_nSize;
		return m_arData[m_nSize];
	}
	int size()
	{
		return m_nSize;
	}
	int empty()
	{
		if (m_nSize)
			return 0;
		return 1;
	}
	int top()
	{
		if (!m_nSize)
			return -1;
		return m_arData[m_nSize - 1];
	}
};

int main()
{
	char szCommand[5][6] = { "push", "pop", "size", "empty", "top" };
	int nCmdNum = 0;
	cin >> nCmdNum;
	
	CStack Stack;
	for (int i = 0; i < nCmdNum; ++i)
	{
		char szInput[6] = "";
		cin >> szInput;
		int nOption = 0;
		for (int j = 0; j < 5; ++j)
			if (!strcmp(szInput, szCommand[j]))
				nOption = j;

		switch (nOption)
		{
		case 0:
			cin >> nOption;
			Stack.push(nOption);
			break;
		case 1:
			cout << Stack.pop() << endl;
			break;
		case 2:
			cout << Stack.size() << endl;
			break;
		case 3:
			cout << Stack.empty() << endl;
			break;
		case 4:
			cout << Stack.top() << endl;
			break;
		}
	}
	
	system("pause");
	return 0;
}