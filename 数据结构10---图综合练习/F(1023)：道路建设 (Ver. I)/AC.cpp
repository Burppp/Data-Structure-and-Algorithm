#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int nodes_num = -1;
int edges_num = -1;
int** matrix;
int* minDist;
bool* connected;
int ans = 0;
void treeBuild()
{
	matrix = new int* [nodes_num];
	connected = new bool[nodes_num];
	minDist = new int[nodes_num];
	for (int i = 0;i < nodes_num;i++)
	{
		matrix[i] = new int[nodes_num];
		for (int j = 0;j < nodes_num;j++)
			cin >> matrix[i][j];
		connected[i] = 0;
		minDist[i] = INT_MAX;
	}
	cin >> edges_num;
	for (int i = 0;i < edges_num;i++)
	{
		int left, right;
		cin >> left >> right;
		left--;
		right--;
		matrix[left][right] = -1;
		matrix[right][left] = -1;
	}
}
void prim()
{
	minDist[0] = 0;
	int min = INT_MAX, min_index = -1;
	ans = 0;
	for (int i = 0;i < nodes_num;i++)
	{
		min_index = -1;
		min = INT_MAX;
		for (int j = 0;j < nodes_num;j++)
			if (connected[j] == 0 && minDist[j] < min)
			{
				min = minDist[j];
				min_index = j;
			}
		connected[min_index] = 1;
		if (minDist[min_index] != -1)
			ans += minDist[min_index];
		for (int j = 0;j < nodes_num;j++)
			if (matrix[min_index][j] < minDist[j] && connected[j] == 0 && matrix[min_index][j] != 0)
				minDist[j] = matrix[min_index][j];
	}
}
int main()
{
	while (cin >> nodes_num)
	{
		treeBuild();
		prim();
		cout << ans << endl;
	}
	return 0;
}
/**********************************************************************
	Problem: 1023
	User: 202200201118
	Language: C++
	Result: AC
	Time:12 ms
	Memory:2220 kb
**********************************************************************/
