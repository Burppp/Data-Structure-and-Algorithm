#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
class Point
{
    double x, y;
public:
    Point();
    Point(double x_value, double y_value);      // 缺省构造函数，给 x, y 分别赋值为0
    ~Point();                                   // 析构函数
    double getX();                              // 返回x的值
    double getY();                              // 返回y的值
    void setXY(double x1, double y1) { x = x1; y = y1; }
    void setX(double x_value);                  // 设置x的值
    void setY(double y_value);                  // 设置y的值
    double getDisTo(Point& p);                  // 计算当前点到参数点p的距离
};
Point::Point()
{
    x = 0;
    y = 0;
    cout << "Constructor." << endl;
}
double Point::getDisTo(Point& p)
{
    double distance = 0;
    distance = sqrt(pow((- p.x + x), 2) + pow(- p.y + y, 2));
    return distance;
}
Point::Point(double x_value, double y_value)
{
    x = x_value;
    y = y_value;
    cout << "Constructor." << endl;
}
Point::~Point()
{
    cout << "Distructor." << endl;
}
double Point::getX()
{
    return x;
}
double Point::getY()
{
    return y;
}
void Point::setX(double x_value)
{
    x = x_value;
}
void Point::setY(double y_value)
{
    y = y_value;
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int num = 0;
        cin >> num;
        Point* p = new Point[num];
        int i = 0, j = 0;
        double x = 0, y = 0;
        for (i = 0; i < num; i++)
        {
            cin >> x >> y;
            p[i].setXY(x, y);
        }
        double max = 0;
        for (i = 0; i < num; i++)
        {
            for (j = i + 1; j < num; j++)
            {
                //double dis = p[i].getDisTo(p[j]);
                if (max < p[i].getDisTo(p[j]))
                    max = p[i].getDisTo(p[j]);
            }
        }
        for (i = 0; i < num; i++)
        {
            for (j = i + 1; j < num; j++)
            {
                if (max == p[i].getDisTo(p[j]))
                {
                    //cout << "The longeset distance is " << max << ",between p[" << i << "] and p[" << j << "].\n";
                    printf("The longeset distance is %.2lf,between p[%d] and p[%d].\n", max, i, j);
                    i = num;
                    break;
                }
            }
        }
        delete[]p;
    }
	return 0;
}
/**********************************************************************
	Problem: 1104
	User: 202200201118
	Language: C++
	Result: AC
	Time:8 ms
	Memory:2224 kb
**********************************************************************/
