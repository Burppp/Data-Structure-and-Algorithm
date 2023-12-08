#include <iostream>
using namespace std;
void graphInit()
{
	int nodes_num;
	cin >> nodes_num;
	int** matrix = new int* [nodes_num];
	for (int i = 0;i < nodes_num;i++)
		matrix[i] = new int[nodes_num];
	for (int i = 0;i < nodes_num;i++)
		for (int j = 0;j < nodes_num;j++)
			cin >> matrix[i][j];
	int sum_in = 0;
	int j = 0;
	int m;
	int out = 0;
	int* ans = new int[nodes_num];
	while(1)
	{
		if (out == nodes_num)
			break;
		for (int i = 0;i < nodes_num;i++)
			sum_in += matrix[i][j];
		if (sum_in == 0)
		{
			ans[out] = j;
			out++;
			for (int k = 0;k < nodes_num;k++)
				matrix[j][k] = 0;
			for (int k = 0;k < nodes_num;k++)
			{
				for (m = 0;m < out;m++)
					if (k == ans[m])
						break;
				if (m == out)
				{
					j = k;
					break;
				}
			}
			sum_in = 0;
			continue;
		}
		sum_in = 0;
		j++;
		for (int i = 0;i < out;i++)
			if (j == ans[i])
				j++;
	}
	for (int i = 0;i < out;i++)
		cout << ans[i] << ' ';
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
		graphInit();
	return 0;
}
/**********************************************************************
	Problem: 1013
	User: 202200201118
	Language: C++
	Result: AC
	Time:9 ms
	Memory:2220 kb
**********************************************************************/
