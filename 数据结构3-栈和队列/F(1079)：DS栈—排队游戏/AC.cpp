#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<int>boys;
    for (int i = 0;i < str.size();i++)
    {
        if (str[i] == str[0])
            boys.push(i);
        else
        {
            cout << boys.top() << ' ' << i << endl;
            boys.pop();
        }
    }
    return 0;
}

/**********************************************************************
	Problem: 1079
	User: 202200201118
	Language: C++
	Result: AC
	Time:8 ms
	Memory:2224 kb
**********************************************************************/
