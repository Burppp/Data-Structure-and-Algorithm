#include <iostream>
using namespace std;
int nodes_num = 0;
int** matrix;
void closure_matrix()
{
	for(int i = 0;i < nodes_num;i++)
		for(int j = 0;j < nodes_num;j++)
			for(int k = 0;k < nodes_num;k++)
				if(matrix[j][i] == 1 && matrix[i][k] == 1)
					matrix[j][k] = 1;
	for(int i = 0;i < nodes_num;i++)
	{
		for(int j = 0;j < nodes_num;j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
}
void graphInit()
{
	cin >> nodes_num;
	matrix = new int*[nodes_num];
	for(int i = 0;i < nodes_num;i++)
	{
		matrix[i] = new int[nodes_num];
		for(int j = 0;j < nodes_num;j++)
			cin >> matrix[i][j];
	}
	closure_matrix();
}
int main()
{
	graphInit();
	return 0;
}
/**********************************************************************
	Problem: 1018
	User: 202200201118
	Language: C++
	Result: AC
	Time:14 ms
	Memory:2220 kb
**********************************************************************/
