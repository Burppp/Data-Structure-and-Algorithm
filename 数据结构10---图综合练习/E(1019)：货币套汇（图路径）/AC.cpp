#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<string,int>index;
int nodes_num = 0;
int rates_num = 0;
double **rates;
string *types;
bool ans;

void floyd()
{
	for(int i = 0;i < nodes_num;i++)
		for(int j = 0;j < nodes_num;j++)
			for(int k = 0;k < nodes_num;k++)
				if(rates[j][k] < rates[j][i] * rates[i][k])
					rates[j][k] = rates[j][i] * rates[i][k];
	for(int i = 0;i < nodes_num;i++)
		if(rates[i][i] > 1.0f)
		{
			ans = true;
			return;
		}
	ans = false;
	return;
}
void graphInit()
{
	cin >> nodes_num >> rates_num;
	types = new string[nodes_num];
	rates = new double*[nodes_num];
	for(int i = 0;i < nodes_num;i++)
	{
		rates[i] = new double[nodes_num];
		cin >> types[i];
		index[types[i]] = i;
	}
	for(int i = 0;i < nodes_num;i++)
		for(int j = 0;j < nodes_num;j++)
			rates[i][j] = 0;
	for(int i = 0;i < rates_num;i++)
	{
		string left,right;
		double rate;
		cin >> left >> rate >> right;
		rates[index[left]][index[right]] = rate;
	}
	ans = false;
	floyd();
	if(ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
int main()
{
	int t = 0;
	cin >> t;
	while (t--)
		graphInit();
	return 0;
}
/**********************************************************************
	Problem: 1019
	User: 202200201118
	Language: C++
	Result: AC
	Time:11 ms
	Memory:2228 kb
**********************************************************************/
