#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int idx = 0;
void DFS(int *&matrix, int size, int index)
{
    if (idx == size)
        return;
    cout << index << ' ';
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
                cout << i << ' ';
                idx++;
                if (idx == size)
                    return;
            }
        }
    }
    return;
}
void graphInit()
{
    int num;
    cin >> num;
    int** matrix = new int* [num + 1];
    for (int i = 0; i < num + 1; i++)
        matrix[i] = new int[num];
    for (int i = 0; i < num; i++)
    {
        matrix[num][i] = 0;
        for (int j = 0; j < num; j++)
            cin >> matrix[i][j];
    }
    idx = 0;
    DFS(matrix[0], num, 0);
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
	Problem: 1009
	User: 202200201118
	Language: C++
	Result: AC
	Time:13 ms
	Memory:2220 kb
**********************************************************************/
