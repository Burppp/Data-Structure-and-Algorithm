#include<iostream>
using namespace std;
string m[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
string* month[12];
int main()
{
	for (int i = 0; i < 12; i++)
	{
		month[i] = &m[i];
	}
	int offset = 0;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> offset;
		if (offset <= 0 || offset >= 13)
		{
			cout << "error" << endl;
			continue;
		}
		cout << *month[offset - 1] << endl;
	}
	return 0;
}
/**********************************************************************
	Problem: 1101
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2220 kb
**********************************************************************/
