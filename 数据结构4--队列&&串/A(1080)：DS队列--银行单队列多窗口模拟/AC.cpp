#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <limits>
using namespace std;
int time_count = 0;
class person
{
public:
    int get_time;
    int handle_time;
    person() :get_time(0), handle_time(0) {}
    void init()
    {
        int g, h;
        cin >> g >> h;
        get_time = g;
        handle_time = h;
    }
};
class window
{
public:
    int from, to;
    window() :from(0), to(0) {}
    void init()
    {
        cin >> from >> to;
    }
    bool handle(person p, bool status)
    {
        if(status)//to status
        {
            from = p.get_time;
            to = from + p.handle_time;
        }
        else
        {
            from = to;
            to = from + p.handle_time;
        }
        return true;
    }
};
int wait_handle(window* Window, int windows)
{
    int first = 0;
    int i;
    for (i = 0; i < windows; i++)
        if (Window[i].to < Window[first].to)
            first = i;
    return first;
}
int main()
{
    int t, i, j;
    int windows;
    int idx = 0;
    int first;
    int delta_max = 0;
    cin >> t;
    person* p = new person[t];
    for (i = 0; i < t; i++)
        p[i].init();
    cin >> windows;
    window* Window = new window[windows];
    queue<person>* qe = new queue<person>[windows];
    vector<int>wait;
    for (i = 0; i < t; i++)
        wait.push_back(0);
    for (i = 0; i < t; i++)
    {
        //choose a window
        for (j = 0; j < windows; j++)
        {
            //no wait
            if (qe[j].empty())
            {
                qe[j].push(p[idx]);
                Window[j].handle(p[idx], 1);
                first = j;
                break;
            }
            //wait
            if (j == windows - 1)
            {
                first = wait_handle(Window, windows);
                qe[first].push(p[idx]);
                //wait
                if (Window[first].to >= p[idx].get_time)
                {
                    qe[first].pop();
                    time_count += Window[first].to - p[idx].get_time;
                    if (delta_max < Window[first].to - p[idx].get_time)
                        delta_max = Window[first].to - p[idx].get_time;
                    Window[first].handle(p[idx], 0);
                    qe[first].push(p[idx]);
                }
                //no wait
                else if (Window[first].to < p[idx].get_time)
                {
                    qe[first].pop();
                    Window[first].handle(p[idx], 1);
                    qe[first].push(p[idx]);
                }
                break;
            }
        }
        idx++;
    }
    int max_time = 0;
    for (i = 0; i < t; i++)
        if (max_time < Window[i].to)
            max_time = Window[i].to;
    printf("%.1lf %d %d\n", (double)(time_count) / t, delta_max, max_time);
    return 0;
}

/**********************************************************************
	Problem: 1080
	User: 202200201118
	Language: C++
	Result: AC
	Time:5 ms
	Memory:2224 kb
**********************************************************************/
