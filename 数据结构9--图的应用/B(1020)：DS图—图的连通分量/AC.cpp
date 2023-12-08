#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
int idx = 0;
int n = 0;
void BFS(int** matrix, int num)
{
	queue<int>qe;
	matrix[num][n] = 1;
	//while (idx != num)
	do
	{
		if (!qe.empty())
		{
			n = qe.front();
			qe.pop();
		}
		for (int j = 0; j < num; j++)
		{
			if (matrix[n][j] && !matrix[num][j])
			{
				//cout << ' ' << j;
				matrix[num][j] = 1;
				qe.push(j);
				idx++;
			}
		}
	} while (!qe.empty());
}
void graphInit()
{
	int nodes_num = -1;
	int edges_num = -1;
	cin >> nodes_num;
	int** matrix = new int* [nodes_num + 1];
	for (int i = 0; i < nodes_num + 1; i++)
		matrix[i] = new int[nodes_num];
	for (int i = 0; i < nodes_num + 1; i++)
		for (int j = 0; j < nodes_num; j++)
			matrix[i][j] = 0;
	map<string, int>mp;
	string *info = new string[nodes_num];
	for (int i = 0; i < nodes_num; i++)
	{
		cin >> info[i];
		mp[info[i]] = i;
	}
	cin >> edges_num;
	for (int i = 0; i < edges_num; i++)
	{
		string left = "", right = "";
		cin >> left >> right;
		int left_idx = -1, right_idx = -1;
		left_idx = mp[left];
		right_idx = mp[right];
		matrix[left_idx][right_idx] = 1;
		matrix[right_idx][left_idx] = 1;
	}
	for(int i = 0;i<nodes_num;i++)
		cout << info[i] << ' ';
	cout << endl;
	for (int i = 0; i < nodes_num; i++)
	{
		for (int j = 0; j < nodes_num; j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
	int sum = 0;
	int count = 0;
	int i = 0;
	while(1)
	{
		idx = 0;
		BFS(matrix, nodes_num);
		sum++;
		for (i = 0; i < nodes_num; i++)
			if (matrix[nodes_num][i] == 0)
			{
				n = i;
				break;
			}
		if (i == nodes_num)
			break;
	}
	cout << sum << endl << endl;
}
int main()
{
	int t = -1;
	cin >> t;
	while (t--)
		graphInit();
	return 0;
}
/**********************************************************************
	Problem: 1020
	User: 202200201118
	Language: C++
	Result: AC
	Time:10 ms
	Memory:2236 kb
**********************************************************************/
