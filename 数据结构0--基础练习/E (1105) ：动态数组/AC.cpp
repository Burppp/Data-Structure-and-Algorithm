#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char ch;
		int num;
		cin >> ch >> num;
		switch (ch)
		{
		case 'I':
		{
			int* p1 = new int[num];
			int avg = 0;
			for (int i = 0; i < num; i++)
			{
				cin >> *(p1+i);
				avg += *(p1+i);
			}
			cout << avg/num << endl;
			break;
		}
		case 'C':
		{
			char* p2 = new char[num];
			cin >> *p2;
			char max = *p2;
			for (int i = 1; i < num; i++)
			{
				cin >> *(p2+i);
				if (max < *(p2+i))
					max = *(p2+i);
			}
			cout << max << endl;
			break;
		}
		case 'F':
		{
			float* p3 = new float[num];
			cin >> *p3;
			float min = *p3;
			for (int i = 1; i < num; i++)
			{
				cin >> *(p3+i);
				if (min > *(p3 + i))
					min = *(p3 + i);
			}
			cout << min << endl;
			break;
		}
		}
	}
	return 0;
}
/**********************************************************************
	Problem: 1105
	User: 202200201118
	Language: C++
	Result: AC
	Time:6 ms
	Memory:2220 kb
**********************************************************************/
