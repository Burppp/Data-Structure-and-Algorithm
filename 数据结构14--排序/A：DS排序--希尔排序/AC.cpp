#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
void xier()
{
	int d = v.size();
	while(1)
	{
		d /= 2;
		for(int i = 0;i < d;i++)
		{
			for(unsigned j = i + d;j < v.size();j += d)
			{
				int temp = v[j];
				int k;
				for(k = j - d;k >= 0 && v[k] < temp;k -= d)
					v[k + d] = v[k];
				v[k + d] = temp;
			}
		}
		for(unsigned i = 0;i < v.size();i++)
			cout << v[i] << ' ';
		cout << endl;
		if(d == 1)
			break;
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int length;
		cin >> length;
		v = vector<int>(length);
		for(int i = 0;i < length;i++)
			cin >> v[i];
		xier();
		cout << endl;
	}
	return 0;
}
/**********************************************************************
	Problem: 1025
	User: 202200201118
	Language: C++
	Result: AC
	Time:10 ms
	Memory:2220 kb
**********************************************************************/
