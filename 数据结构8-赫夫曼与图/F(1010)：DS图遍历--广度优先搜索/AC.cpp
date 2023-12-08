#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class GraphNode
{
public:
    int data;
    int index;
    bool visited;
    //GraphNode** neighbors;
    vector<GraphNode*>neighbors;

    GraphNode() :data(-1), index(-1), visited(0) {}
    GraphNode(int d, int i) :data(d), index(i), visited(0) {}
};
int idx = 0;
void BFS(int** matrix, int num)
{
    queue<int>qe;
    int n = 0;
    while(idx != num)
    {
        if(!qe.empty())
        {
            n = qe.front();
            qe.pop();
        }
        for (int j = 0; j < num; j++)
        {
            if (matrix[n][j] && !matrix[num][j])
            {
                cout << ' ' << j;
                matrix[num][j] = 1;
                qe.push(j);
                idx++;
            }
        }
    }
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
    matrix[num][0] = 1;
    idx = 1;
    cout << '0';
    BFS(matrix, num);
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
	Problem: 1010
	User: 202200201118
	Language: C++
	Result: AC
	Time:9 ms
	Memory:2220 kb
**********************************************************************/
