#include <iostream>
using namespace std;
int BubbleSort(int *list, int length)
{
	int count = 0;
	for(int i = 0;i < length;i++)
	{
		for(int j = i;j < length;j++)
		{
			if(list[i] > list[j])
			{
				int temp = list[i];
				list[i] = list[j];
				list[j] = temp;
				count++;
			}
		}
	}
	return count;
}
int main()
{
	int t;
	while(cin >> t)
	{
		int *list = new int[t];
		for(int i = 0;i < t;i++)
			cin >> list[i];
		int result = BubbleSort(list, t);
		cout << result << endl;
	}
	return 0;
}
