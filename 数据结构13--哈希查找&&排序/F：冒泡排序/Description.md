Description
二种操作：

1 Key 表示插入一个新数据Key；
2 K 输出当前数据从小到大排列的第 K个数，并删除这个数，不存在则输出-1。
要求使用平衡树实现

#include<stdio.h>
const int maxn = 1e5 + 10;
struct Node
{
    int key;        // 关键值
    int data;       // 携带的数据
    int left;       // 左子树地址（数组下标）
    int right;      // 右子树地址（数组下标）
    int height;     // 当前结点为根的子树高度
    void Init(){data = key = left = right = height = -1;}
    void Init(int k_, int d_=0){Init(); key = k_; data = d_;}
    Node(){Init();}
    Node(int k_, int d_=0){Init(k_, d_);}
};

Node tr[maxn];
int root, tp;  // root标记根节点位置，tp全局结点分配下标

inline int UpdateHeight(int now)
{
    // 更新 tr[now] 结点的子树高度，即tr[now].height的值
}
inline int HeightDiff(int now)
{
    // 计算 tr[now] 结点的平衡因子
}
int LL(int an)
{
}
int RR(int an)
{
}
int LR(int an)
{
}
int RL(int an)
{
}
void Insert(int &now, int key, int data=0)
{
    if(now == -1)
    {
        // 传入指针为空，新建结点保存数据
        now = ++ tp;
        tr[now].Init(key, data);
    }
    // 判断插入哪个子树，插入数据，判断平衡因子，做正确旋转，更新高度
}
void Delete(int &now, int key)
{
    if(now == -1) return;
    else if(key < tr[now].key) Delete(tr[now].left, key);
    else if(key > tr[now].key) Delete(tr[now].right, key);
    else
    {
        // 删除当前结点
    }
    // 处理树平衡
}

int main()
{
    int n, op, key, data;
    while(scanf("%d", &n) != EOF)
    {
        root = tp = -1;
        while(n --)  // 初始化根结点和“内存指针”
        {
            scanf("%d", &op);
            if(op == 1)
            {
            }
            else if(op == 2)
            {
            }           
    }
    return 0;
}
Input
每组数据第一行n表示有n个操作

接下来n行操作内容


Output
按操作规则输出对应内容

Sample
#0
Input
8
1 1
1 2
1 3
1 4
1 5
2 2
2 2
2 6
Output
2
3
-1