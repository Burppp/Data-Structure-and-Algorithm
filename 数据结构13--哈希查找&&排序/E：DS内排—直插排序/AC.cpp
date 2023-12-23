#include <iostream>
using namespace std;
class Binary_tree
{
public:
	char* datas;
	int data_size;

	Binary_tree() : datas(NULL), data_size(0) {}
	Binary_tree(int size)
	{
		data_size = size;
		datas = new char[data_size];
	}
	Binary_tree(char* external_datas, int size)
	{
		data_size = size;
		datas = external_datas;
	}
	int BalanceFactor_helper(int index)
	{
		if (datas[index] == '0' || index >= data_size)
		{
			return 0;
		}
		int left_level = BalanceFactor_helper(2 * index + 1);
		int right_level = BalanceFactor_helper(2 * index + 2);
		cout << datas[index] << ' ' << left_level - right_level << endl;
		if (left_level > right_level)
			return left_level + 1;
		else
			return right_level + 1;
	}
	void BalanceFactor()
	{
		char* output_char = new char[data_size];
		int* output_int = new int[data_size];
		int start_index = 0, output_pointer = 0;
		BalanceFactor_helper(start_index);
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int num;
		cin >> num;
		char* datas = new char[num];
		for (int i = 0; i < num; i++)
			cin >> datas[i];
		Binary_tree* tree = new Binary_tree(datas, num);
		tree->BalanceFactor();
	}
	return 0;
}
/**********************************************************************
	Problem: 1042
	User: 202200201118
	Language: C++
	Result: AC
	Time:10 ms
	Memory:2224 kb
**********************************************************************/
