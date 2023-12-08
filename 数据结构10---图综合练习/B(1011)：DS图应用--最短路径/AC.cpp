#include <iostream>
#include <climits>
#include <vector>
#include <stack>
using namespace std;
int nodes_num = 0;
int source_node = -1;
int** matrix;
int* previous_node;
int* visited;
int* distance_ans;

void Dijkstra(int source_node)
{
	int area_nodes = 0, min = INT_MAX, min_index = -1;
	distance_ans[source_node] = 0;
	while (nodes_num - area_nodes - 1)
	{
		min = INT_MAX;
		min_index = -1;
		for (int i = 0; i < nodes_num; i++)
		{
			if (visited[i] == 0 && distance_ans[i] < min)
			{
				min = distance_ans[i];
				min_index = i;
			}
		}
		visited[min_index] = 1;
		for (int i = 0; i < nodes_num; i++)
		{
			if (min + matrix[min_index][i] < distance_ans[i] && matrix[min_index][i] != 0)
			{
				distance_ans[i] = min + matrix[min_index][i];
				previous_node[i] = min_index;
			}
		}
		area_nodes++;
	}

	for (int i = 0; i < nodes_num; i++)
	{
		if (i == source_node)
			continue;
		stack<int>path;
		cout << source_node << "-" << i << "-" << distance_ans[i] << "----[";
		path.push(i);
		int previous_path = i;
		while (path.top() != source_node)
		{
			path.push(previous_node[previous_path]);
			previous_path = previous_node[previous_path];
		}
		while (!path.empty())
		{
			cout << path.top() << " ";
			path.pop();
		}
		cout << "]" << endl;
	}
}
void graphInit()
{
	cin >> nodes_num;
	previous_node = new int[nodes_num];
	visited = new int[nodes_num];
	distance_ans = new int[nodes_num];
	matrix = new int* [nodes_num];
	for (int i = 0; i < nodes_num; i++)
	{
		matrix[i] = new int[nodes_num];
		for (int j = 0; j < nodes_num; j++)
			cin >> matrix[i][j];
		previous_node[i] = -1;
		visited[i] = 0;
		distance_ans[i] = INT_MAX;
	}
	cin >> source_node;
	Dijkstra(source_node);
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
	Problem: 1011
	User: 202200201118
	Language: C++
	Result: AC
	Time:13 ms
	Memory:2224 kb
**********************************************************************/
