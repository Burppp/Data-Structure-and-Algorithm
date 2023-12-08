#include <iostream>
using namespace std;
int main()
{
	int t, arr[100], i, num, * p, temp;
	cin >> t;
	while (t--)
	{
		cin >> num;
		for (i = 0; i < num; i++)
		{
			cin >> arr[i];
		}
		p = arr;
		p = arr + num / 2 - 1;
		cout << *p << ' ' << *(p+2) << endl;
		cin >> temp;
		p = arr;
		cout << *(p + temp - 1) << endl;
	}
	return 0;
}
/**********************************************************************
	Problem: 1102
	User: 202200201118
	Language: C++
	Result: AC
	Time:6 ms
	Memory:2220 kb
**********************************************************************/
