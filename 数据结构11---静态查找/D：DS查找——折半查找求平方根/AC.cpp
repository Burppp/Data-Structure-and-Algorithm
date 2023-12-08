#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
double sqrtMine(double num)
{
	double dummySqrt = num / 2;
	double last_less = 0, last_more = num;
	while (fabsf(dummySqrt * dummySqrt - num) >= 0.00001)
	{
		if (dummySqrt * dummySqrt - num > 0.00001)//大了
		{
			last_more = dummySqrt;
			dummySqrt = (dummySqrt + last_less) / 2;
		}
		else if (dummySqrt * dummySqrt - num < -0.00001)//小了
		{
			last_less = dummySqrt;
			dummySqrt = (dummySqrt + last_more) / 2;
		}
	}
	return dummySqrt;
}
int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		double num = 0;
		cin >> num;
		double result = sqrtMine(num);
		printf("%.3f\n", result);
	}
	return 0;
}
/**********************************************************************
	Problem: 1049
	User: 202200201118
	Language: C++
	Result: AC
	Time:12 ms
	Memory:2220 kb
**********************************************************************/
