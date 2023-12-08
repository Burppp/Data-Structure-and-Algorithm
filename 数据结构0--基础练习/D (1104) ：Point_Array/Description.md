Description
class Point
{
    double x, y;
public:
    Point();
    Point(double x_value, double y_value);      // 缺省构造函数，给 x, y 分别赋值为0
    ~Point();                                   // 析构函数
    double getX();                              // 返回x的值
    double getY();                              // 返回y的值
    void setXY(double x1, double y1){x = x1; y = y1;}
    void setX(double x_value);                  // 设置x的值
    void setY(double y_value);                  // 设置y的值
    double getDisTo(Point &p);                  // 计算当前点到参数点p的距离
}
上面是我们曾经练习过的一个习题，请在原来代码的基础上作以下修改：

增加自写的拷贝构造函数；
增加自写的析构函数；
将getDisTo方法的参数修改为getDisTo(const Point &p)；
根据下面输出的内容修改相应的构造函数。
然后在主函数中根据用户输入的数目建立Point数组，求出数组内距离最大的两个点之间的距离值。

Input
测试数据的组数 t

第一组点的个数

第一个点的 x 坐标 y坐标

第二个点的 x坐标 y坐标

............

Output
输出第一组距离最大的两个点以及其距离

...........

在C++中，输出指定精度的参考代码如下：

#include <iostream>
#include <iomanip> //必须包含这个头文件
using namespace std;
void main( )
{ 
    double a =3.141596;
    cout<<fixed<<setprecision(3)<<a<<endl;  //输出小数点后3位
...
C中如下：

printf("%.3f\n", a);
Sample
#0
Input
2
4
0 0
5 0
5 5
2 10
3
-1 -8
0 9
5 0
Output
Constructor.
Constructor.
Constructor.
Constructor.
The longeset distance is 10.44,between p[1] and p[3].
Distructor.
Distructor.
Distructor.
Distructor.
Constructor.
Constructor.
Constructor.
The longeset distance is 17.03,between p[0] and p[1].
Distructor.
Distructor.
Distructor.