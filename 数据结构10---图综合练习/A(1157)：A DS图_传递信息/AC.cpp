#include <iostream>
using namespace std;
int len = 0;
int nodes_num = 0;
int k = 0;
int ans = 0;

static void DFS(int** matrix, int num, int now)
{
	if (num == nodes_num - 1 && now == 0)
	{
		ans++;
		return;
	}
	for (int i = 0;i < nodes_num;i++)
		if (matrix[num][i] == 1 && now > 0)
			DFS(matrix, i, now - 1);
	return;
}
static void graphInit()
{
	cin >> nodes_num >> len;
	int** matrix = new int* [nodes_num + 1];
	for (int i = 0; i < nodes_num + 1; i++)
		matrix[i] = new int[nodes_num];
	for (int i = 0; i < nodes_num + 1; i++)
		for (int j = 0; j < nodes_num; j++)
			matrix[i][j] = 0;
	for (int i = 0; i < len; i++)
	{
		int left = 0, right = 0;
		cin >> left >> right;
		matrix[left][right] = 1;
	}
	cin >> k;
	ans = 0;
	DFS(matrix, 0, k);
	cout << ans << endl;
}
int main()
{
	int t = 0;
	cin >> t;
	while (t--)
		graphInit();
	return 0;
}
/**********************************************************************
	Problem: 1157
	User: 202200201118
	Language: C++
	Result: AC
	Time:13 ms
	Memory:2220 kb
**********************************************************************/
