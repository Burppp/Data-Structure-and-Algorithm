#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
#include <limits.h>
/*检索是否有同一组的元素已经存在，如果有，
则新元素排在同组的最后，如果没有则插入队列末尾。*/
using namespace std;
int search(int** arr, int num, vector<int> qe_j, int qe_i)
{
	int i, j;
	for (i = 0;i < qe_i;i++)
		for (j = 0;j < qe_j[i];j++)
			if (num == arr[i][j])
				return i;
	return -1;
}
int main()
{
	int qe_i, i, j, k, pos, enq, pri = 0;
	bool status = 1;
	cin >> qe_i;
	vector<int>qe_j;
	int** arr = new int* [qe_i];
	//未重复数index = qe_i
	queue<int> *qe = new queue<int>[qe_i + 1];
	int* prio = new int[qe_i + 1];
	for (i = 0;i < qe_i + 1;i++)
		prio[i] = -1;
	for (i = 0;i < qe_i;i++)
	{
		cin >> j;
		arr[i] = new int[j];
		qe_j.push_back(j);
		for (k = 0;k < j;k++)
			cin >> arr[i][k];
	}
	string oper;
	while (cin >> oper && oper != "STOP")
	{
		if (oper == "ENQUEUE")
		{
			cin >> enq;
			pos = search(arr, enq, qe_j, qe_i);
			if(qe[pos].empty())
				prio[pos] = pri++;
			if (pos == -1)
				qe[qe_i].push(enq);
			else
				qe[pos].push(enq);
		}
		if (oper == "DEQUEUE")
		{
			int min = INT_MAX;
			for (i = 0;i < qe_i + 1;i++)
				if (prio[i] >= 0 && min > prio[i] && !qe[i].empty())
					min = prio[i];
			for (i = 0;i < qe_i + 1;i++)
				if (min == prio[i])
					break;
			if (!status)
				cout << ' ' << qe[i].front();
			else
			{
				status = 0;
				cout << qe[i].front();
			}
			qe[i].pop();
			if (qe[i].empty())
			{
				prio[i] = -1;
				for (i = 0;i < qe_i + 1;i++)
					prio[i]--;
			}
		}
	}
	return 0;
}
/**********************************************************************
	Problem: 1078
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2224 kb
**********************************************************************/
