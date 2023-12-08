#include<iostream>
using namespace std;
int main()
{
	int t, i, j, n = 3;
	int arr[3][3];
	int(* p)[3] = arr;
	cin >> t;
	while (t--)
	{
		for (i = 0;i < 2;i++)
			for (j = 0;j < 3;j++)
				cin >> *(* (p + i) + j);
		for (i = 2;i >= 0;i--)
		{
			for (j = 0;j <= 1;j++)
				cout << *( * (p + j) + i) << ' ';
			cout << endl;
		}
	}
	return 0;
}
/**********************************************************************
	Problem: 1106
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2220 kb
**********************************************************************/
