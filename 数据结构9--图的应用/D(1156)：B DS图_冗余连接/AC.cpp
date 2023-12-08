#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class treeNode
{
public:
	bool tag;
	int info;
	vector<treeNode*>next;
	vector<int>length;
	treeNode() :tag(0), info(-1) {}
	treeNode(int i) :tag(0), info(i) {}
};
int idx = 0;
int n = 0;
int nodes_num;
vector<pair<int, int>>edges;
vector<pair<int, int>>ans;
vector<int>area;
bool flag = 0;
bool status = 0;
bool check_loop()
{
	if (ans.begin()->first == ans.back().second)
		return true;
	return false;
}
void DFS_loop(int** matrix, int matrix_i, int matrix_j)
{
	int j;
	for (int i = matrix_i;i < nodes_num;i++)
	{
		for (j = matrix_j;j < nodes_num;j++)
		{
			if (matrix[i][j] == 1)
			{
				matrix[j][i] = 0;
				if (find(area.begin(), area.end(), j) != area.end())
				{
					//ans.push_back({ j + 1,i + 1 });
					if (ans.empty())
						ans.push_back({ min(j + 1,i + 1),max(j + 1,i + 1) });
					if(!status)
						ans.push_back({ min(j + 1,i + 1),max(j + 1,i + 1) });
					status = check_loop();
					return;
				}
				area.push_back(i);
				DFS_loop(matrix, j, 0);
				if (!flag)
				{
					if(ans.empty())
						ans.push_back({ min(j + 1,i + 1),max(j + 1,i + 1) });
					if (!status)
						ans.push_back({ min(j + 1,i + 1),max(j + 1,i + 1) });
					status = check_loop();
					return;
				}
				else
					flag = 0;
			}
		}
		if (j == nodes_num)
		{
			flag = 1;
			return;
		}
	}
}
void graphInit()
{
	cin >> nodes_num;
	int** matrix = new int* [nodes_num];
	for (int i = 0;i < nodes_num;i++)
		matrix[i] = new int[nodes_num];
	for (int i = 0;i < nodes_num;i++)
		for (int j = 0;j < nodes_num;j++)
			matrix[i][j] = 0;
	treeNode** nodes = new treeNode * [nodes_num];
	for (int i = 0;i < nodes_num;i++)
		nodes[i] = new treeNode(i);
	int left, right;
	for (int i = 0;i < nodes_num;i++)
	{
		cin >> left >> right;
		matrix[left - 1][right - 1] = 1;
		matrix[right - 1][left - 1] = 1;
		edges.push_back({ left,right });
	}
	DFS_loop(matrix, 0, 0);
	for (int i = edges.size() - 1;i >= 0;i--)
	{
		auto it = find(ans.begin(), ans.end(), edges[i]);
		if (it != ans.end())
		{
			cout << it->first << ' ' << it->second << endl;
			break;
		}
	}
	edges.erase(edges.begin(), edges.end());
	ans.erase(ans.begin(), ans.end());
	area.erase(area.begin(), area.end());
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
	Problem: 1156
	User: 202200201118
	Language: C++
	Result: AC
	Time:12 ms
	Memory:2224 kb
**********************************************************************/
