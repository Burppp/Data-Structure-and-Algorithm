#include<iostream>
#include<vector>
using namespace std;
void graphInit()
{
    int n, k;
    cin >> n >> k;
    int** matrix = new int* [n];
    for (int i = 0;i < n;i++)
        matrix[i] = new int[n];
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            matrix[i][j] = 0;
    char* ch = new char[n];
    for (int i = 0;i < n;i++)
        cin >> ch[i];
    for (int i = 0;i < k;i++)
    {
        char first, second;
        cin >> first >> second;
        int idx1, idx2;
        for (int j = 0;j < n;j++)
        {
            if (ch[j] == first)
                idx1 = j;
            if (ch[j] == second)
                idx2 = j;
        }
        matrix[idx1][idx2]++;
    }
    for (int i = 0;i < n;i++)
    {
        cout << i << ' ' << ch[i];
        for (int j = 0;j < n;j++)
            if (matrix[i][j] != 0)
                cout << '-' << j;
        cout << "-^" << endl;
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
	Problem: 1014
	User: 202200201118
	Language: C++
	Result: AC
	Time:9 ms
	Memory:2220 kb
**********************************************************************/
