#include <iostream>
#include <vector>
using namespace std;
int class_num;
vector<pair<int, int>>pairs;
bool check_loop()
{
	for (int i = 0;i < pairs.size();i++)
	{
		for (int j = 0;j < pairs.size();j++)
		{
			if (pairs[i].second == pairs[j].first)
				pairs[i].second = pairs[j].second;
			if (pairs[i].first == pairs[i].second)
				return true;
		}
	}
	return false;
}
int main()
{
	int t;

	int len;
	cin >> t;
	while (t--)
	{
		cin >> class_num >> len;
		int left, right;
		for (int i = 0;i < len;i++)
		{
			cin >> left >> right;
			pairs.push_back({ left,right });
		}
		if (check_loop())
			cout << "false" << endl;
		else
			cout << "true" << endl;
		pairs.erase(pairs.begin(), pairs.end());
	}
	return 0;
}
/**********************************************************************
	Problem: 1153
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2220 kb
**********************************************************************/
