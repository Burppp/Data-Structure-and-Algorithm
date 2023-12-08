#include <iostream>
using namespace std;
int idx = 0;
void DFS(int*& matrix, int size, int index)
{
	if (idx == size)
		return;
	//cout << index << ' ';
	int offset = -index + size;
	(*(&matrix + offset))[index] = 1;
	idx++;
	if (idx == size)
		return;
	for (int j = 0; j < size; j++)
		if (matrix[j] == 1 && !(*(&matrix + offset))[j])
			DFS(*(&matrix + j - index), size, j);
	if (idx != size)
	{
		for (int i = 0; i < size; i++)
		{
			if ((*(&matrix + offset))[i] == 0)
			{
				if (idx == size)
					return;
				//cout << i << ' ';
				idx++;
				if (idx == size)
					return;
			}
		}
	}
	return;
}
void judge(int** matrix, int size)
{
	int j;
	bool status = 0;
	for (int i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			if (matrix[i][j] != matrix[j][i])
			{
				status = 1;//有向图
				break;
			}
		if (j != size)
			break;
	}
	if (status)//有向图
	{
		for(int i = 0;i<size;i++)
			for(int j = 0;j<size;j++)
				if (matrix[i][j] == 0 && i != j)
				{
					cout << "No" << endl;
					return;
				}
		cout << "Yes" << endl;
		return;
	}
	else
	{
		DFS(matrix[0], size, 0);
	}
	for(int i=0;i<size;i++)
		if (matrix[size][i] == 0)
		{
			cout << "No" << endl;
			return;
		}
	cout << "Yes" << endl;
	return;
}
int main()
{
	int k = -1;
	int nodes_num = -1;
	cin >> k;
	while (k--)
	{
		cin >> nodes_num;
		int** matrix = new int* [nodes_num + 1];
		for (int i = 0; i < nodes_num + 1; i++)
			matrix[i] = new int[nodes_num];
		for (int i = 0; i < nodes_num; i++)
		{
			for (int j = 0; j < nodes_num; j++)
				cin >> matrix[i][j];
			matrix[nodes_num][i] = 0;
		}
		//DFS(matrix[i], nodes_num, i);
		judge(matrix, nodes_num);
	}
	return 0;
}
/**********************************************************************
	Problem: 1012
	User: 202200201118
	Language: C++
	Result: AC
	Time:9 ms
	Memory:2220 kb
**********************************************************************/
