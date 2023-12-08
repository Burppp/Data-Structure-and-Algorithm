#include<iostream>
using namespace std;
#define ok 0
#define error -1
int length;
int length1, length2;
int n, k, s;
// 链表结点定义
class ListNode
{
public:
    int data;
    int num;
    ListNode* next;
    ListNode* before;
    ListNode() { next = NULL; }
    ListNode(int i) :data(i) {}
};
// 带头结点的单链表类定义
class LinkList
{
public:
    ListNode* head;
    int len;
    // 操作定义
    LinkList();
    ~LinkList();
    ListNode* LL_index(int i);      // 返回第i个结点的指针，如果不存在返回NULL
    int LL_get(int i);              // 获取第i个元素的数据
    int LL_insert(int i, int item); // 把数值item插入第i个位置
    int LL_del(int i);              // 删除第i个结点
    void LL_display();              // 输出单链表的内容
    void LL_merge(ListNode* v);                //合并链表
    void LL_search(int l);
    void out_line(int n, int k, int s);
    void creatList();
};
void LinkList::creatList()
{
    cin >> n >> k >> s;
    length = n;
    int id = 1;
    int* num = new int[n];
    int i;
    for (i = 0;i < n;i++)
        num[i] = 0;
    ListNode** arr = new ListNode * [n];
    for (i = 0;i < n;i++)
    {
        arr[i] = new ListNode(0);
        arr[i]->num = id++;
    }
    arr[0]->data = num[0];
    arr[0]->before = arr[n - 1];
    arr[0]->next = arr[1];
    for (i = 1;i < n;i++)
    {
        arr[i]->data = num[i];
        if (i != n - 1)
        {
            arr[i]->before = arr[i - 1];
            arr[i]->next = arr[i + 1];
        }
        else
        {
            arr[i]->before = arr[i - 1];
            arr[i]->next = arr[0];
        }
    }
    head = *arr;
}
void LinkList::out_line(int n, int k, int s)
{
    //1-N
    //n个人数从第s个人开始到k出列
    int count = 1;
    int total = 0;
    int* arr = new int[n + 1];
    for (int i = 0;i < n + 1;i++)
        arr[i] = 1;
    int del_node = 0;
    ListNode* cur = head;
    for (int i = 1;i < s;i++)
        cur = cur->next;
    int n1 = n;
    while (n1--)
    {
        for (count = 1;count < k;count++)
            cur = cur->next;
        cout << cur->num << ' ';
        for (int i = 1;i <= cur->num;i++)
            total += arr[i];
        this->LL_del(total);
        total = 0;
        arr[cur->num] = 0;
        cur = cur->next;
        /*while (count != k)
        {
            cur = cur->next;
            count++;
        }
        if (count == k)
        {
            cout << cur->num << ' ';
            for (int i = 0;i < cur->num;i++)
                total += arr[i];
            this->LL_del(total);
            total = 0;
            arr[cur->num] = 0;
            cur = cur->next;
            count = 1;
        }*/
    }
    cout << endl;
}
void LinkList::LL_search(int l)
{
    ListNode* cur = head;
    int count = 0;
    while (cur->data != l && cur)
    {
        cur = cur->next;
        count++;
    }
    if (cur->before == nullptr && cur->next != nullptr)
        cout << cur->next->data << endl;
    if (cur->before != nullptr && cur->next == nullptr)
        cout << cur->before->data << endl;
    if (cur->before != nullptr && cur->next != nullptr)
        cout << cur->before->data << ' ' << cur->next->data << endl;
}
void LinkList::LL_merge(ListNode* v)
{
    ListNode** ans = new ListNode * [length1 + length2];
    for (int i = 0;i < length1 + length2;i++)
        ans[i] = new ListNode(0);
    ListNode* start = *ans;
    ListNode* cur1 = head;
    ListNode* cur2 = v;
    int count = 0;
    while (cur1 && cur2)
    {
        ans[count++]->data = cur1->data > cur2->data ? cur2->data : cur1->data;
        if (cur1->data > cur2->data)
            cur2 = cur2->next;
        else
            cur1 = cur1->next;
    }
    if (cur1 == nullptr && cur2 != nullptr)
    {
        while(cur2)
        {
            ans[count++]->data = cur2->data;
            cur2 = cur2->next;
        }
    }
    else
    {
        while (cur1)
        {
            ans[count++]->data = cur1->data;
            cur1 = cur1->next;
        }
    }
    count -= 1;
    ans[count]->next = NULL;
    int i = 0;
    for (i = 1;i < length1 + length2 - 1;i++)
    {
        ans[i - 1]->next = ans[i];
    }
    for (i = 0;i < length1 + length2;i++)
    {
        cout << ans[i]->data << ' ';
    }
    cout << endl;
}
int LinkList::LL_get(int i)              // 获取第i个元素的数据
{
    if (head == NULL || i <= 0 || i > length)
    {
        cout << "error" << endl;
        return error;
    }
    ListNode* cur = head;
    for (int j = 1;j < i;j++)
        cur = cur->next;
    cout << cur->data << endl;
    return cur->data;
}
int LinkList::LL_del(int i)              // 删除第i个结点
{
    //if (head == NULL || i <= 0 || i > length - 1)
    //{
    //    //cout << "error" << endl;
    //    return error;
    //}
    if (i == 1 && length == 1)
    {
        return ok;
    }
    if (i == 1)
    {
        ListNode* last = head->before;
        head = head->next;
        last->next = head;
        head->before = last;
        //this->LL_display();
        return ok;
    }
    ListNode* cur = head;
   /* for (int j = 1;j < i - 1;j++)
        cur = cur->next;
    ListNode* later = cur->next->next;
    cur->next = later;*/
    for (int j = 1;j < i;j++)
        cur = cur->next;
    ListNode* before = cur->before;
    ListNode* next = cur->next;
    before->next = next;
    next->before = before;
    //this->LL_display();
    return ok;
}
int LinkList::LL_insert(int i, int item) // 把数值item插入第i个位置
{
    if (head == NULL || i < 0 || i > length + 1)
    {
        cout << "error" << endl;
        return error;
    }
    if (i == 1)
    {
        ListNode* insert_spe = new ListNode(item);
        insert_spe->next = head;
        head = insert_spe;
        this->LL_display();
        return ok;
    }
    ListNode* cur = head;
    ListNode* insert = new ListNode(item);
    for (int j = 1;j < i - 1;j++)
        cur = cur->next;
    ListNode* later = cur->next;
    cur->next = insert;
    insert->next = later;
    this->LL_display();
    return ok;
}

LinkList::LinkList()
{
    /*head = new ListNode();
    len = 0;*/
    //n个人数从第s个人开始到k出列
    cin >> n >> k >> s;
    length = n;
    int id = 1;
    int* num = new int[n];
    int i;
    for (i = 0;i < n;i++)
        num[i] = 0;
    ListNode** arr = new ListNode * [n];
    for (i = 0;i < n;i++)
    {
        arr[i] = new ListNode(0);
        arr[i]->num = id++;
    }
    arr[0]->data = num[0];
    arr[0]->before = arr[n - 1];
    arr[0]->next = arr[1];
    for (i = 1;i < n;i++)
    {
        arr[i]->data = num[i];
        if (i != n - 1)
        {
            arr[i]->before = arr[i - 1];
            arr[i]->next = arr[i + 1];
        }
        else
        {
            arr[i]->before = arr[i - 1];
            arr[i]->next = arr[0];
        }
    }
    head = *arr;
    //this->LL_display();
}
LinkList::~LinkList()
{
    /*ListNode* p, * q;
    p = head;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
    len = 0;
    head = NULL;*/
}
void LinkList::LL_display()
{
    ListNode* p;
    p = head;
    while (p)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    /*LinkList list;
    int status = 1;*/
    while (t--)
    {
        /*if (status)
        {
            status = 0;
            list.out_line(n, k, s);
            continue;
        }*/
        LinkList list;
        //list.creatList();
        list.out_line(n, k, s);
    }
    return 0;
}
/**********************************************************************
	Problem: 1092
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2224 kb
**********************************************************************/
