#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int>arr, int target)
{
	int size = arr.size();
	int right = size, left = 0, mid = (right + left) / 2;
	while(right >= left)
	{
		if(target < arr[mid])
		{
			right = mid - 1;
			mid = (right + left) / 2;
		}
		if(target > arr[mid])
		{
			left = mid + 1;
			mid = (right + left) / 2;
		}
		if(target == arr[mid])
			return mid + 1;
	}
	return -1;
}
int main()
{
	int t;
	cin >> t;
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
		int target = 0;
		cin >> target;
		if(target > arr.back() || target < arr[0])
		{
			cout << "error" << endl;
			continue;
		}
		int result = binarySearch(arr,target);
		if(result == -1)
			cout << "error" << endl;
		else
			cout << result << endl;
	}
	return 0;
}
/**********************************************************************
	Problem: 1047
	User: 202200201118
	Language: C++
	Result: AC
	Time:17 ms
	Memory:2360 kb
**********************************************************************/
