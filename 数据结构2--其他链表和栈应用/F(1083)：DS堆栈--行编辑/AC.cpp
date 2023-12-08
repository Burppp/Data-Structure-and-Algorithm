#include<stack>
#include<iostream>
#include<vector>
using namespace std;
#include <string>
int main()
{
    int t;
    cin >> t;
    string str;
    stack<char>stk;
    stack<char>ans;
    while (t--)
    {
        cin >> str;
        for (auto& c : str)
        {
            if (c == '#' && !stk.empty())
                stk.pop();
            else if (c == '#')
                ;
            else
                stk.push(c);
        }
        while (!stk.empty())
        {
            ans.push(stk.top());
            stk.pop();
        }
        if (ans.empty())
            cout << "NULL";
        while (!ans.empty())
        {
            cout << ans.top();
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}
/**********************************************************************
	Problem: 1083
	User: 202200201118
	Language: C++
	Result: AC
	Time:6 ms
	Memory:2224 kb
**********************************************************************/
