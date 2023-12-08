#include <iostream>
#include <stdio.h>
using namespace std;

class item
{
	int num[100] = { 0 };
	int subnum[100] = { 0 };
public:
	item(int n)
	{
		int n1, n2;
		while (n--)
		{
			cin >> n1 >> n2;
			if (n2 >= 0)
				num[n2] += n1;//n2次方的x有n1个
			else
				subnum[-n2] = n1;
		}
	}
	void add(item& v)
	{
		int i = 0;
		for (i = 0;i < 100;i++)
		{
			num[i] += v.num[i];
		}
		for (i = -99;i < 0;i++)
		{
			subnum[-i] += v.subnum[-i];
		}
	}
	void print()
	{
		bool flag = 1;
		for (int i = -9;i < 0;i++)
		{
			if (flag && subnum[-i])
			{
				if (subnum[-i] > 0)
					printf("%dx^(%d)", subnum[-i], i);
				else
					printf("(%d)", subnum[-i]);
				flag = 0;
				continue;
			}
			if (subnum[-i])
			{
				cout << " + ";
				if (subnum[-i] > 0)
					printf("%dx^(%d)", subnum[-i], i);
				if (subnum[-i] < 0)
					printf("(%d)x^(%d)", subnum[-i], i);
			}
		}
		for (int i = 0;i < 100;i++)
		{
			if (flag && num[i])
			{
				if (i == 0)
				{
					if (num[i] > 0)
						cout << num[i];
					else
						printf("(%d)", num[i]);
				}
				else
				{
					if (num[i] > 0)
						cout << num[i] << "x^" << i;
					else
						printf("(%d)", num[i]);
				}
				flag = 0;
				continue;
			}
			if (num[i] == 0)
				continue;
			if (i == 0)
			{
				cout << " + ";
				if (num[i] > 0)
					cout << num[i];
				else
					printf("(%d)", num[i]);
			}
			else
			{
				cout << " + ";
				if (num[i] > 0)
					cout << num[i] << "x^" << i;
				if (num[i] < 0)
					printf("(%d)x^%d", num[i],i);
			}
		}
		cout << endl;
	}
};

int main()
{
	int t, num;
	cin >> t;
	while (t--)
	{
		cin >> num;
		item temp1(num);
		temp1.print();
		cin >> num;
		item temp2(num);
		temp2.print();
		temp1.add(temp2);
		temp1.print();
	}
	return 0;
}
/**********************************************************************
	Problem: 1090
	User: 202200201118
	Language: C++
	Result: AC
	Time:8 ms
	Memory:2220 kb
**********************************************************************/
