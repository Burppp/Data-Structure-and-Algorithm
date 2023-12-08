#include<stack>
#include<iostream>
#include<vector>
using namespace std;
#include <string>
int main()
{
    stack<char>stk;
    int t, i = 0;
    cin >> t;
    string str;
    while (t--)
    {
        cin >> str;
        for(auto &c:str)
            stk.push(c);
        while (!stk.empty())
        {
            cout << stk.top();
            stk.pop();
        }
        cout << endl;
    }
    return 0;
}
/**********************************************************************
	Problem: 1081
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2224 kb
**********************************************************************/
