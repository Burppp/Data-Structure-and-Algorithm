#include <iostream>
using namespace std;
int length, keys;
void Init(int* Hash)
{
	for (int i = 0;i < length;i++)
		Hash[i] = -1;
}
void Insert(int* Hash, int num)
{
	int value = num % 11;
	int count = 1, HashIndex, times = 0;
	HashIndex = value;
	while (1)
	{
		if(Hash[HashIndex] == -1)
		{
			Hash[HashIndex] = num;
			break;
		}
		if(times % 2 == 0)
		{
			HashIndex = value + count * count;
			HashIndex %= length;
			times++;
		}
		else
		{
			HashIndex = value - count * count;
			while(HashIndex < 0)
				HashIndex = (HashIndex + 100 * length) % length;
			times++;
			count++;
		}
	}
}
void Print(int* Hash)
{
	for (int i = 0;i < length;i++)
	{
		if (Hash[i] != -1)
			cout << Hash[i];
		else
			cout << "NULL";
		if (i != length - 1)
			cout << ' ';
	}
	cout << endl;
}
void Search(int* Hash, int num)
{
	int times = 0, value, HashIndex, search = 1, count = 0;
	value = num % 11;
	HashIndex = value;
	while (1)
	{
		if(times >= length)
			break;
		times++;
		if (Hash[HashIndex] == num)
		{
			cout << "1 " << times << ' ' << HashIndex + 1 << endl;
			return;
		}
		if (Hash[HashIndex] == -1)
			break;
		if(count % 2 == 0)
		{
			HashIndex = (value + search * search) % length;
			count++;
		}
		else
		{
			HashIndex = value - search * search;
			while(HashIndex < 0)
				HashIndex = (HashIndex + 100 * length) % length;
			search++;
			count++;
		}
	}
	cout << "0 " << times << endl;
}
int main()
{
	int t = 0;
	int* Hash = NULL;
	cin >> t;
	while (t--)
	{
		cin >> length >> keys;
		Hash = new int[length];
		Init(Hash);
		while (keys--)
		{
			int num;
			cin >> num;
			Insert(Hash, num);
		}
		Print(Hash);
		int num;
		cin >> num;
		while (num--)
		{
			int target;
			cin >> target;
			Search(Hash, target);
		}
	}
	delete[] Hash;
	return 0;
}
