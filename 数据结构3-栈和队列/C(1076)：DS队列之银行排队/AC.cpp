#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	queue<int> myQe[3];
	int t, i, sum = 0, count = 0;
	cin >> t;
	char* p = new char[t];
	int* num = new int[t];
	for (i = 0;i < t;i++)
	{
		cin >> p[i];
	}
	for (i = 0;i < t;i++)
		cin >> num[i];
	for (i = 0;i < t;i++)
	{
		switch (p[i])
		{
		case 'A':
			myQe[0].push(num[i]);
			break;
		case 'B':
			myQe[1].push(num[i]);
			break;
		case 'C':
			myQe[2].push(num[i]);
			break;
		}
	}
	for (i = 0;i < 3;i++)
	{
		count = myQe[i].size();
		while (!myQe[i].empty())
		{
			sum += myQe[i].front();
			myQe[i].pop();
		}
		cout << sum / count << endl;
		sum = 0;
	}
	return 0;
}
/**********************************************************************
	Problem: 1076
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2220 kb
**********************************************************************/
