#include <iostream>
using namespace std;
const int maxn = 1e3 + 10;
int Hash[maxn];
int length, keys;
void Init()
{
	for(int i = 0;i < length;i++)
		Hash[i] = -1;
}
int NextIndex(int index)
{
	int count = 0;
	while(1)
	{
		if(count > length)
			return -1;
		if(Hash[index] == -1)
			return index;
		index++;
		index = index % length;
		count++;
	}
}
void Insert(int num)
{
	int HashIndex = num % 11;
	HashIndex = NextIndex(HashIndex);
	if(HashIndex != -1)
		Hash[HashIndex] = num;
}
void Print()
{
	for(int i = 0;i < length;i++)
	{
		if(Hash[i] != -1)
			cout << Hash[i] << ' ';
		else
			cout << "NULL ";
	}
	cout << endl;
}
void Search(int num)
{
	int HashIndex = num % 11;
	int count = 1;
	while(1)
	{
		if(Hash[HashIndex] == -1 || Hash[HashIndex] == num)
		{
			break;
		}
		if(count >= length)
		{
			HashIndex = -1;
			break;
		}
		HashIndex++;
		HashIndex  = HashIndex % length;
		count++;
	}
	if(HashIndex == -1)
	{
		cout << "0 " << count << endl;
		return;
	}
	if(Hash[HashIndex] == -1)
		cout << "0 " << count << endl;
	else
		cout << "1 " << count << ' ' << HashIndex + 1 << endl;
}
int main()
{
	int t = 0;
	cin >> t;
	while(t--)
	{
		cin >> length >> keys;
		Init();
		while(keys--)
		{
			int num;
			cin >> num;
			Insert(num);
		}
		Print();
		int num;
		cin >> num;
		while(num--)
		{
			int target;
			cin >> target;
			Search(target);
		}
	}
	return 0;
}
/**********************************************************************
  Problem: 1036
  User: 202200201118
  Language: C++
  Result: AC
  Time:29 ms
  Memory:2224 kb
 **********************************************************************/

