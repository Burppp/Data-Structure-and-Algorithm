#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
vector<list<int>>Hash(11);
void Set()
{
	for(int i = 0;i < 11;i++)
		Hash[i].clear();
}
void Insert(int num)
{
	int HashIndex = num % 11;
	Hash[HashIndex].push_front(num);
}
void Search(int num)
{
	int HashIndex = num % 11;
	auto result = find(Hash[HashIndex].begin(), Hash[HashIndex].end(), num);
	if (result == Hash[HashIndex].end())
	{
		cout << "error" << endl;
		Insert(num);
		return;
	}
	auto it = result;
	int index = 0;
	while (it != Hash[HashIndex].begin())
	{
		it--;
		index++;
	}
	cout << HashIndex << ' ' << index + 1 << endl;
}
int main()
{
	int length;
	while(cin >> length)
	{
		Set();
		while (length--)
		{
			int num;
			cin >> num;
			Insert(num);
		}
		cin >> length;
		while (length--)
		{
			int num;
			cin >> num;
			Search(num);
		}
	}
	return 0;
}
