#include <iostream>
#include <stack>
using namespace std;
void clear_stack(stack<char>* stk)
{
	while (!stk->empty())
	{
		stk->pop();
	}
}
int main()
{
	int t, i;
	int status = 1;
	string str;
	stack <char>stk;
	cin >> t;
	while (t--)
	{
		status = 1;
		cin >> str;
		for (i = 0;i < str.size();i++)
		{
			if (str[i] == '[' || str[i] == '(' || str[i] == '{')
			{
				stk.push(str[i]);
				continue;
			}
			if (str[i] == ']' || str[i] == ')' || str[i] == '}')
			{
				if (stk.empty())
				{
					cout << "error" << endl;
					break;
				}
				else
				{
					if (str[i] == ']' && stk.top() == '[')
						stk.pop();
					else if (str[i] == ')' && stk.top() == '(')
						stk.pop();
					else if (str[i] == '}' && stk.top() == '{')
						stk.pop();
					else
					{
						break;
					}
				}
			}
		}
		if (!stk.empty())
		{
			cout << "error" << endl;
			clear_stack(&stk);
			continue;
		}
		if (i == str.size())
			cout << "ok" << endl;
	}
	return 0;
}
/**********************************************************************
	Problem: 1084
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2224 kb
**********************************************************************/
