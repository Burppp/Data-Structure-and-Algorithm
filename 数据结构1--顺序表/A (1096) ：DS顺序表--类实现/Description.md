Description
实现顺序表的用C++语言和类实现顺序表

属性包括：数组、实际长度、最大长度（设定为1000）

操作包括：创建、插入、删除、查找

类定义参考

#include<iostream>
using namespace std;
#define ok 0
#define error -1

// 顺序表类定义
class SeqList
{
private:
    int *list;      // 元素数组
    int maxsize;    // 顺序表最大长度
    int size;       // 顺序表实际长度
public:
    SeqList();                          // 构造函数
    ~SeqList();                         // 析构函数
    int list_size();                    // 获取顺序表实际长度
    int list_insert(int i, int item);   // 插入一个元素，参数是插入的数值和位置
    int list_del(int i);                // 删除一个元素，参数是删除的位置
    int list_get(int i);                // 获取一个元素，参数是获取的位置
    void list_display();                // 输出整个顺序表
};

SeqList::SeqList()
{
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}
SeqList::~SeqList()
{
    delete []list;
}
Input
第1行先输入n表示有n个数据，即n是实际长度；接着输入n个数据
第2行输入要插入的位置和新数据
第3行输入要插入的位置和新数据
第4行输入要删除的位置
第5行输入要删除的位置
第6行输入要查找的位置
第7行输入要查找的位置
Output
数据之间用空格隔开

第1行输出创建后的顺序表内容，包括顺序表实际长度和数据

每成功执行一次操作（插入或删除），输出执行后的顺序表内容

每成功执行一次查找，输出查找到的数据

如果执行操作失败（包括插入、删除、查找等失败），输出字符串error，不必输出顺序表内容

Sample
#0
Input
6 11 22 33 44 55 66
3 777
1 888
1
9
0
5
Output
6 11 22 33 44 55 66 
7 11 22 777 33 44 55 66 
8 888 11 22 777 33 44 55 66 
7 11 22 777 33 44 55 66 
error
error
44
Hint
第i个位置是逻辑意义的位置，从1开始，在实际编程用数组，从0开始，对应数组i-1位置