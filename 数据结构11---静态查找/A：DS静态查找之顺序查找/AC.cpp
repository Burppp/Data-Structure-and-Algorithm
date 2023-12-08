#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>arr,int target)
{
	vector<int> arr_cp = arr;
	arr_cp.push_back(target);
	int size = arr_cp.size(), i;
	for(i = 0;arr_cp[i] != target;i++);
	arr_cp.pop_back();
	if(i < size - 1)
		return i + 1;
	else
		return -1;
}
int main()
{
	int t;
	while(cin >> t)
	{
		vector<int>arr;
		while(t--)
		{
			int temp = 0;
			cin >> temp;
			arr.push_back(temp);
		}
		cin >> t;
		while(t--)
		{
			int temp = 0;
			cin >> temp;
			int result = search(arr, temp);
			if(result == -1)
				cout << "error" << endl;
			else
				cout << result << endl;
		}
	}
	return 0;
}
/**********************************************************************
	Problem: 1046
	User: 202200201118
	Language: C++
	Result: AC
	Time:95 ms
	Memory:2220 kb
**********************************************************************/
