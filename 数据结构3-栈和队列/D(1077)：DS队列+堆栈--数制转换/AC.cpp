#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
int main()
{
	double num, num2, ans = 0;
	int num1, count = 3;
	int t, tf, i;
	stack<int> _int;
	queue<int> _double;
	cin >> t;
	while (t--)
	{
		count = 3;
		cin >> num >> tf;
		num1 = (int)num;
		num2 = num - num1;
		while (num1)
		{
			_int.push(num1 % tf);
			num1 = num1 / tf;
		}
		for(i=0;i<3;i++)
		{
			num2 = num2 * tf;
			_double.push(((int)num2) % tf);
		}
		while (!_int.empty())
		{
			if (_int.top() >= 10)
			{
				cout << (char)('A' + _int.top() - 10);
			}
			else
			{
				cout << _int.top();
			}
			_int.pop();
		}
		cout << '.';
		while (!_double.empty())
		{
			if (_double.front() >= 10)
			{
				cout << (char)('A' + _double.front() - 10);
			}
			else
			{
				cout << _double.front();
			}
			_double.pop();
			count--;
		}
		cout << endl;
	}
	return 0;
}
/**********************************************************************
	Problem: 1077
	User: 202200201118
	Language: C++
	Result: AC
	Time:9 ms
	Memory:2224 kb
**********************************************************************/
