#include<iostream>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
char cmp(stack<char>* stk, char* ch, int status)
{
    char a = stk->top();
    int pri1 = 0, pri2 = 0;
    if (a == '+' || a == '-')
        pri1 = 0;
    else
        pri1 = 1;
    if (*ch == '+' || *ch == '-')
        pri2 = 0;
    else
        pri2 = 1;
    if(status)
    {
        if (pri1 <= pri2)
            return *ch;
        if (pri1 > pri2)
        {
            stk->pop();
            stk->push(*ch);
            return a;
        }
    }
    else
    {
        if (pri1 <= pri2)
            stk->push(*ch);
        else
        {
            stk->pop();
            stk->push(*ch);
            stk->push(a);
        }
    }
    return '#';
}
string pol(string str)
{
    stack<char>operation;
    stack<char>num;
    string ans;
    bool right_status = 0, left_status = 0;
    for (int i = str.size() - 1;i >= 0;i--)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (operation.empty())
                operation.push(str[i]);
            else
            {
                if (right_status && left_status)
                {
                    ans.push_back(cmp(&operation, &str[i], right_status && left_status));
                    ans.push_back(' ');
                    right_status = left_status = 0;
                }
                else
                    cmp(&operation, &str[i], right_status && left_status);
            }
        }
        else if (str[i] == ')' || str[i] == '(')
        {
            int j = i;
            while (str[j] != '(')
                j--;
            string son = str.substr(j + 1, i - j - 1);
            ans += pol(son);
            ans.push_back(' ');
            i = j;
            right_status = 1;
            left_status = 1;
        }
        else
        {
            ans.push_back(str[i]);
            if (i == 0)
                ans.push_back(' ');
            else if (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/')
            {
                if (right_status)
                    left_status = 1;
                else
                    right_status = 1;
                ans.push_back(' ');
            }
        }
    }
    while(!operation.empty())
    {
        ans.push_back(operation.top());
        if (operation.size() != 1)
            ans.push_back(' ');
        operation.pop();
    }
    return ans;
}
string anti_pol(string str)
{
    int status = 0;
    stack<char>operation;
    string ans;
    for (int i = 0;i < str.size();i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (operation.empty())
                operation.push(str[i]);
            else
            {
                cmp(&operation, &str[i], status == 3);
            }
        }
        else if (str[i] == ')' || str[i] == '(')
        {
            int j = i;
            while (str[j] != ')')
                j++;
            string son = str.substr(i + 1, j - i - 1);
            ans += anti_pol(son);
            ans.push_back(' ');
            i = j;
            status = 0;
        }
        else
        {
            ans.push_back(str[i]);
            if (i == str.size() - 1)
                ans.push_back(' ');
            else if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/')
            {
                status++;
                ans.push_back(' ');
                if (status == 3)
                {
                    ans.push_back(operation.top());
                    ans.push_back(' ');
                    operation.pop();
                    ans.push_back(operation.top());
                    ans.push_back(' ');
                    operation.pop();
                    status = 0;
                }
            }
        }
    }
    while (!operation.empty())
    {
        ans.push_back(operation.top());
        if (operation.size() != 1)
            ans.push_back(' ');
        operation.pop();
    }
    return ans;
}
int main()
{
    int t;
    string pol_oper;
    string anti_pol_oper;
    cin >> t;
    while (t--)
    {
        string oper;
        cin >> oper;
        pol_oper =  pol(oper);
        reverse(pol_oper.begin(), pol_oper.end());
        cout << pol_oper << endl;
        anti_pol_oper = anti_pol(oper);
        cout << anti_pol_oper << endl << endl;
    }
    return 0;
}

/**********************************************************************
	Problem: 1109
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2232 kb
**********************************************************************/
