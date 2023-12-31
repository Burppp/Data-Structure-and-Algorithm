#include <iostream>
#include <vector>
using namespace std;
vector<int> origin;
void SelectSort()
{
	for (unsigned i = 1; i < origin.size(); i++)
	{
		if (origin[i] < origin[i - 1])
		{
			unsigned j;
			for (j = 0; j < i; j++)
				if (origin[j] > origin[i])
					break;
			int temp = origin[i];
			origin.erase(origin.begin() + i);
			origin.insert(origin.begin() + j, temp);
		}
	}
}
void MinDist()
{
	vector<int>dist = vector<int>(origin.size() - 1);
	for (unsigned i = 1; i < origin.size(); i++)
		dist[i - 1] = origin[i] - origin[i - 1];
	int min = dist[0];
	for (unsigned i = 0; i < dist.size(); i++)
		if (min > dist[i])
			min = dist[i];
	for (unsigned i = 0; i < dist.size(); i++)
	{
		if (dist[i] == min)
			cout << '[' << origin[i] << ',' << origin[i + 1] << "] ";
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int num;
		cin >> num;
		origin = vector<int>(num);
		for (int i = 0; i < num; i++)
			cin >> origin[i];
		SelectSort();
		MinDist();
	}
	return 0;
}
/**********************************************************************
	Problem: 1139
	User: 202200201118
	Language: C++
	Result: AC
	Time:9 ms
	Memory:2220 kb
**********************************************************************/
