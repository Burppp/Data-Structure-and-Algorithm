#include<iostream>
using namespace std;
#define ok 0
#define error -1
int length;
// 链表结点定义
class ListNode
{
public:
    int data;
    ListNode* next;
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
};
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
    if (head == NULL || i <= 0 || i > length - 1)
    {
        cout << "error" << endl;
        return error;
    }
    if (i == 1)
    {
        head = head->next;
        this->LL_display();
        return ok;
    }
    ListNode* cur = head;
    for (int j = 1;j < i - 1;j++)
        cur = cur->next;
    ListNode* later = cur->next->next;
    cur->next = later;
    this->LL_display();
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
    cin >> len;
    length = len;
    int* num = new int[len];
    int i;
    for (i = 0;i < len;i++)
        cin >> num[i];
    ListNode** arr = new ListNode * [len];
    for (i = 0;i < len;i++)
    {
        arr[i] = new ListNode(0);
    }
    for (i = 0;i < len;i++)
    {
        arr[i]->data = num[i];
        if (i != len - 1)
            arr[i]->next = arr[i + 1];
        else
            arr[i]->next = NULL;
    }
    head = *arr;
    this->LL_display();
}
LinkList::~LinkList()
{
    ListNode* p, * q;
    p = head;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
    len = 0;
    head = NULL;
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
    LinkList list;
    int k = 2;
    int i, item;
    for (int j = 0;j < k;j++)
    {
        cin >> i >> item;
        list.LL_insert(i, item);
    }
    for (int j = 0;j < k;j++)
    {
        cin >> i;
        list.LL_del(i);
    }
    for (int j = 0;j < k;j++)
    {
        cin >> i;
        list.LL_get(i);
    }
    return 0;
}
/**********************************************************************
	Problem: 1087
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2220 kb
**********************************************************************/
