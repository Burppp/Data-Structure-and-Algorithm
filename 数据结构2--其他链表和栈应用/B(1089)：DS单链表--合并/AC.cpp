#include<iostream>
using namespace std;
#define ok 0
#define error -1
int length;
int length1, length2;
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
    void LL_merge(ListNode* v);                //合并链表
};
void LinkList::LL_merge(ListNode* v)
{
    ListNode** ans = new ListNode * [length1 + length2];
    for (int i = 0;i < length1 + length2;i++)
        ans[i] = new ListNode(0);
    ListNode* start = *ans;
    ListNode* cur1 = head;
    ListNode* cur2 = v;
    int count = 0;
    while (cur1->next && cur2->next)
    {
        ans[count++]->data = cur1->data > cur2->data ? cur2->data : cur1->data;
        if (cur1->data > cur2->data)
            cur2 = cur2->next;
        else
            cur1 = cur1->next;
    }
    if (cur1->next == nullptr && cur2->next != nullptr)
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
    for (i = 0;i < length1 + length2 - 1;i++)
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
    if (length1 == 0)
        length1 = len;
    else
        length2 = len;
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
    //this->LL_display();
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
    LinkList list1;
    LinkList list2;
    list1.LL_merge(list2.head);
    return 0;
}
/**********************************************************************
	Problem: 1089
	User: 202200201118
	Language: C++
	Result: WA
**********************************************************************/
