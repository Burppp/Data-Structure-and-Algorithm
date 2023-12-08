#include<iostream>
#include<algorithm>
using namespace std;
#define ok 0
#define error -1
#define swap(a,b) a=a^b,b=b^a,a=a^b;
// 顺序表类定义
class SeqList
{
private:
    int* list;      // 元素数组
    int maxsize;    // 顺序表最大长度
    int size;       // 顺序表实际长度
public:
    SeqList();                          // 构造函数
    SeqList(int t);                          // 构造函数
    SeqList(int t, bool flag);                          // 构造函数
    ~SeqList();                         // 析构函数
    int list_size();                    // 获取顺序表实际长度
    int list_insert(int i, int item);   // 插入一个元素，参数是插入的数值和位置
    int list_del(int i);                // 删除一个元素，参数是删除的位置
    int list_get(int i);                // 获取一个元素，参数是获取的位置
    void list_display();                // 输出整个顺序表
    void error_handle();
    void multiinsert(int i, int n, int item[]);
    void multidel(int i, int n);
    void hebing(SeqList& list2);
    void move(bool flag, int num);
    void check();
};

void SeqList::check()
{
    int arr1[1000] = {0};
    int arr0[1000] = { 0 };
    int i;
    bool flag = 0;
    for (i = 0;i < size;i++)
    {
        if (list[i] < 0)
        {
            arr0[-list[i]]++;
            continue;
        }
        arr1[list[i]]++;
    }
    for (i = 0;i < size;i++)
    {
        if (flag)
        {
            i--;
            flag = 0;
        }
        if (list[i] > 0 && arr1[list[i]] > 1)
        {
            this->list_del(i + 1);
            //==this->list_display();
            arr1[list[i]]--;
            flag = 1;
        }
        if (list[i] < 0 && arr0[-list[i]] > 1)
        {
            this->list_del(i + 1);
            //this->list_display();
            arr0[-list[i]]--;
            flag = 1;
        }
    }
    this->list_display();
}
void SeqList::move(bool flag, int num)
{
    num = num % size;
    int i;
    if (flag == 1)//right
    {
        for (i = size - 1;i >= 0;i--)
        {
            list[i + num] = list[i];
        }
        for (i = 0;i < num;i++)
        {
            list[i] = list[size + i];
        }
    }
    else//left
    {
        int* temp = new int[num];
        int count = 0;
        for (i = 0;i < num;i++)
        {
            temp[i] = list[i];
        }
        for (i = num;i < size;i++)
        {
            list[i - num] = list[i];
        }
        for (i = size - num;i < size;i++)
        {
            list[i] = temp[count++];
        }
    }
    this->list_display();
}
SeqList::SeqList(int t, bool flag)                          // 构造函数
{
    maxsize = 1000;
    size = t;
    list = new int[maxsize];
}
void SeqList::hebing(SeqList& list2)
{
    int temp = this->list_size() + list2.list_size();
    bool flag = 1;
    SeqList ans(temp,flag);
    int i;
    for (i = 0; i < list_size(); i++)
    {
        ans.list[i] = list[i];
    }
    int count = 0;
    int j;
    for (j = 0; j < list2.list_size(); j++)
    {
        ans.list[i++] = list2.list[count++];
    }
    sort(ans.list, &ans.list[ans.list_size()]);
    ans.list_display();
}


void SeqList::multidel(int i, int n)
{
    if (i <= 0 || i > size + 1)
    {
        this->error_handle();
        return;
    }
    int j;
    for (j = i - 1 + n; j < size; j++)
    {
        list[j - n] = list[j];
    }
    size -= n;
    this->list_display();
}

void SeqList::multiinsert(int i, int n, int item[])
{
    if (i <= 0 || i > size + 1)
    {
        this->error_handle();
        return;
    }
    int j;
    for (j = size - 1; j > i - 5 + n; j--)
    {
        list[j + n] = list[j];
        //this->list_display();
    }
    int count = 0;
    for (j = i - 1; j < i + n - 1; j++)
    {
        list[j] = item[count++];
        //this->list_display();
    }
    size += n;
    this->list_display();
}

void SeqList::error_handle()
{
    cout << "error" << endl;
}
SeqList::SeqList()
{
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}
SeqList::SeqList(int t)                          // 构造函数
{
    maxsize = 1000;
    size = t;
    list = new int[maxsize];
    int i;
    for (i = 0; i < size; i++)
    {
        cin >> list[i];
    }
    //this->list_display();
}
SeqList::~SeqList()
{
    delete[]list;
}
int SeqList::list_size()                    // 获取顺序表实际长度
{
    return size;
}
int SeqList::list_insert(int i, int item)   // 插入一个元素，参数是插入的数值和位置
{
    //item = offset
    if (item <= 0 || item > size + 1)
    {
        this->error_handle();
        return 0;
    }
    int j;
    for (j = size - 1;j > item - 2;j--)
    {
        list[j + 1] = list[j];
        //this->list_display();
    }
    list[item - 1] = i;
    size++;
    this->list_display();
    return 0;
}
int SeqList::list_del(int i)                // 删除一个元素，参数是删除的位置
{
    if (i <= 0 || i > size)
    {
        this->error_handle();
        return 0;
    }
    int j = 0;
    for (j = 0; j < size; j++)
    {
        if (j < i - 1)
            continue;
        else
        {
            list[j] = list[j + 1];
        }
    }
    size--;
    //this->list_display();
    return 0;
}
int SeqList::list_get(int i)                // 获取一个元素，参数是获取的位置
{
    if (i <= 0 || i > size)
    {
        this->error_handle();
        return 0;
    }
    //this->list_display();
    cout << list[i - 1];
    return list[i];
}
void SeqList::list_display()                // 输出整个顺序表
{
    int i = 0;
    cout << size << ' ';
    cout << list[i];
    for (i = 1; i < size; i++)
    {
        cout << ' ' << list[i];
    }
    cout << ' ';
    cout << endl;
}

int main()
{
    int t,num;
    cin >> t;
    while (t--)
    {
        cin >> num;
        if (!num)
        {
            cout << "0 ";
            continue;
        }
        SeqList list(num);
        list.check();
    }
    return 0;
}
/**********************************************************************
	Problem: 1204
	User: 202200201118
	Language: C++
	Result: AC
	Time:8 ms
	Memory:2224 kb
**********************************************************************/
