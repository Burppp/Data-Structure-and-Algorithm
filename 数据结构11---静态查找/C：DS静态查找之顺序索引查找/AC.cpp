#include <iostream>
#include <vector>
using namespace std;
void blocks(vector<int>& nums, vector<vector<int>>& parts, int*& MaxinPart)
{
	int size = nums.size();
	int cur_col = 0;
	for (int i = 0;i < size;i++)
	{
		if (nums[i] > MaxinPart[cur_col])
			cur_col++;
		if (nums[i] <= MaxinPart[cur_col])
			parts[cur_col].push_back(nums[i]);
	}
}
void SearchinBlock(vector<vector<int>>& parts, int*& MaxinPart, int target)
{
	int target_index = -1, search_times = 0, target_colume = parts.size() - 1;
	int columes = parts.size(), i;
	for (i = 0;i < columes;i++)
	{
		if (MaxinPart[i] == target)
		{
			target_colume = i;
			break;
		}
		if (MaxinPart[i] > target)
		{
			target_colume = i;
			break;
		}
	}
	search_times += target_colume + 1;
	for (int i = 0;i < parts[target_colume].size();i++)
		if (parts[target_colume][i] == target)
		{
			target_index = i + 1;
			break;
		}
	if (target_index == -1)
	{
		cout << "error" << endl;
		return;
	}
	search_times += target_index;
	for (int i = 0;i < target_colume;i++)
		target_index += parts[i].size();
	cout << target_index << '-' << search_times << endl;
	return;
}
int main()
{
	int num = 0;
	while (cin >> num)
	{
		vector<int>nums(num);
		for (int i = 0;i < num;i++)
			cin >> nums[i];
		cin >> num;
		vector<vector<int>>parts(num);
		int* MaxinPart = new int[num];
		for (int i = 0;i < num;i++)
			cin >> MaxinPart[i];
		cin >> num;
		int* targets = new int[num];
		for (int i = 0;i < num;i++)
			cin >> targets[i];
		blocks(nums, parts, MaxinPart);
		for (int i = 0;i < num;i++)
			SearchinBlock(parts, MaxinPart, targets[i]);
	}
	return 0;
}
/**********************************************************************
	Problem: 1048
	User: 202200201118
	Language: C++
	Result: AC
	Time:26 ms
	Memory:2224 kb
**********************************************************************/
