#include<iostream>
using namespace std;
class GraphNode
{
public:
    string data;
    int index;
    GraphNode** neighbors;
    //vector<GraphNode*>neighbors;

    GraphNode() :data("#"), index(-1), neighbors(NULL) {}
    GraphNode(string d, int i) :data(d), index(i), neighbors(NULL) {}
};

void graphInit()
{
    char type;
    int num;
    cin >> type >> num;
    int* p = new int[num];
    GraphNode** graph = new GraphNode * [num];
    for (int i = 0;i < num;i++)
        graph[i] = new GraphNode();
    int** matrix = new int* [num];
    for (int i = 0;i < num;i++)
        matrix[i] = new int[num];
    for (int i = 0;i < num;i++)
    {
        p[i] = 0;
        for (int j = 0;j < num;j++)
            matrix[i][j] = 0;
    }
    string* str = new string[num];
    for (int i = 0;i < num;i++)
    {
        cin >> str[i];
        graph[i]->data = str[i];
        graph[i]->index = i;
        graph[i]->neighbors = new GraphNode * [num];
        for (int j = 0;j < num;j++)
            graph[i]->neighbors[j] = new GraphNode[num];
    }
    int num_pairs;
    cin >> num_pairs;
    for (int i = 0;i < num_pairs;i++)
    {
        string first, second;
        cin >> first >> second;
        int idx1, idx2;
        for (int j = 0;j < num;j++)
        {
            if (str[j] == first)
                idx1 = j;
            if (str[j] == second)
                idx2 = j;
        }
        matrix[idx1][idx2]++;
        graph[idx1]->neighbors[p[idx1]++] = graph[idx2];
    }
    if (type == 'U')
    {
        for (int i = 0;i < num;i++)
            for (int j = 0;j < num;j++)
                if (matrix[i][j])
                    matrix[j][i] = matrix[i][j];
        for (int i = 0;i < num;i++)
        {
            int count = 0;
            for (int j = 0;j < num;j++)
                count += matrix[i][j];
            p[i] = count;
        }
    }
    for (int i = 0;i < num;i++)
    {
        cout << matrix[i][0];
        for (int j = 1;j < num;j++)
            cout << ' ' << matrix[i][j];
        cout << endl;
    }
    if (type == 'D')//有向图，入度、出度、度
    {
        for (int i = 0;i < num;i++)
        {
            cout << str[i];
            int sum_in = 0;
            int sum_out = 0;
            for (int j = 0;j < num;j++)
            {
                sum_in += matrix[j][i];
                sum_out += matrix[i][j];
            }
            if(sum_out || sum_in)
                cout << ':' << ' ' << sum_out << ' ' << sum_in << ' ' << sum_in + sum_out << endl;
        }
    }
    if (type == 'U')//无向图，度
    {
        for (int i = 0;i < num;i++)
        {
            cout << str[i];
            if (p[i])
                cout << ':' << ' ' << p[i];
            cout << endl;
        }
    }
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
	Problem: 1015
	User: 202200201118
	Language: C++
	Result: AC
	Time:13 ms
	Memory:2224 kb
**********************************************************************/
