#include <iostream>
#include <climits>
#include <vector>
#include <stack>
using namespace std;
int nodes_num = 0;
int path_num = 0;
int source_node = -1;
int** matrix;
//int* previous_node;
int* visited;
int* distance_ans;
static void Dijkstra(int source_node)
{
	int area_nodes = 0, min = INT_MAX, min_index = -1;
	distance_ans[source_node] = 0;
	while (nodes_num - area_nodes - 1)
	{
		min = INT_MAX;
		min_index = -1;
		for (int i = 0; i < nodes_num; i++)
		{
			if (visited[i] == 0 && distance_ans[i] <= min)
			{
				min = distance_ans[i];
				min_index = i;
			}
		}
		visited[min_index] = 1;
		for (int i = 0; i < nodes_num; i++)
		{
			if (visited[i] == 0 && matrix[min_index][i] != 0 && distance_ans[min_index] != INT_MAX && distance_ans[min_index] + matrix[min_index][i] < distance_ans[i])
			{
				distance_ans[i] = min + matrix[min_index][i];
				//previous_node[i] = min_index;
			}
		}
		area_nodes++;
	}
	//for (int i = 0; i < nodes_num; i++)
	//{
	//	if (i == source_node)
	//		continue;
	//	stack<int>path;
	//	path.push(i);
	//	int previous_path = i;
	//	while (path.top() != source_node)
	//	{
	//		path.push(previous_node[previous_path]);
	//		previous_path = previous_node[previous_path];
	//	}
	//	while (!path.empty())
	//		path.pop();
	//}
}
static void graphInit()
{
	cin >> nodes_num >> path_num;
	//previous_node = new int[nodes_num];
	visited = new int[nodes_num];
	distance_ans = new int[nodes_num];
	matrix = new int* [nodes_num];
	for (int i = 0; i < nodes_num; i++)
	{
		matrix[i] = new int[nodes_num];
		//previous_node[i] = -1;
		visited[i] = 0;
		distance_ans[i] = INT_MAX;
	}
	for (int i = 0; i < nodes_num; i++)
		for (int j = 0; j < nodes_num; j++)
			matrix[i][j] = 0;
	for (int i = 0; i < path_num; i++)
	{
		int from = 0, to = 0, cost = 0;
		cin >> from >> to >> cost;
		if (matrix[from - 1][to - 1] == 0 || cost < matrix[from - 1][to - 1])
			matrix[from - 1][to - 1] = matrix[to - 1][from - 1] = cost;
	}
	source_node = 0;
}
int main()
{
	graphInit();
	Dijkstra(source_node);
	cout << distance_ans[nodes_num - 1] << endl;
	return 0;
}
/**********************************************************************
	Problem: 1021
	User: 202200201118
	Language: C++
	Result: AC
	Time:27 ms
	Memory:6180 kb
**********************************************************************/
