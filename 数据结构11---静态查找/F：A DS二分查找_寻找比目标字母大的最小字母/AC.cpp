#include <iostream>
#include <string>
#include <vector>
using namespace std;
char minCharInString(string& str, char target)
{
	vector<int>StringCompareToChar;
	for (int i = 0;i < str.size();i++)
		StringCompareToChar.push_back((int)str[i] - (int)target);
	if (StringCompareToChar.back() <= 0)
		return str[0];
	int left = 0, right = StringCompareToChar.size(), mid = (left + right) / 2;
	while (left < right)
	{
		if (left == right - 1)
			break;
		if (StringCompareToChar[mid] > 0)
		{
			right = mid - 1;
			mid = (left + right) / 2;
		}
		if (StringCompareToChar[mid] <= 0)
		{
			left = mid + 1;
			mid = (left + right) / 2;
		}
	}
	for(int i = mid;i < StringCompareToChar.size();i++)
		if(StringCompareToChar[i] > 0)
			return str[i];
	return str[mid];
}
int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		string str;
		char target;
		cin >> str >> target;
		char result = minCharInString(str, target);
		cout << result << endl;
	}
	return 0;
}
/**********************************************************************
	Problem: 1115
	User: 202200201118
	Language: C++
	Result: AC
	Time:10 ms
	Memory:2224 kb
**********************************************************************/
