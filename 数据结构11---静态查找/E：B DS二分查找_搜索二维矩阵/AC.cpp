#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int columns = 0, lines = 0;
	cin >> lines >> columns;
	vector<vector<int>>matrix(lines, vector<int>(columns));
	for (int i = 0;i < lines;i++)
		for (int j = 0;j < columns;j++)
			cin >> matrix[i][j];
	int t = 0;
	cin >> t;
	while (t--)
	{
		int target = 0, i;
		cin >> target;
		int target_line = lines - 1;
		for (int i = 0;i < lines;i++)
			if (matrix[i][0] > target)
			{
				target_line = i - 1;
				break;
			}
		for (i = 0;i < matrix[target_line].size();i++)
			if (matrix[target_line][i] == target)
			{
				cout << "true" << endl;
				break;
			}
		if (i == matrix[target_line].size())
			cout << "false" << endl;
	}
	return 0;
}
/**********************************************************************
	Problem: 1113
	User: 202200201118
	Language: C++
	Result: AC
	Time:12 ms
	Memory:2220 kb
**********************************************************************/
