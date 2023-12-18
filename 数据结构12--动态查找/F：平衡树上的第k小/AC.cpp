#include <iostream>
#include <vector>
using namespace std;
class Binary_tree_node;
const int maxn = 1e5 + 10;
int keys[100000] = { 0 };
enum
{
	LL_ = 1,
	RR_ = 2,
	LR_ = 3,
	RL_ = 4
};
class Binary_tree_node
{
public:
	int key;        // 关键值
	int data;       // 携带的数据
	int left;       // 左子树地址（数组下标）
	int right;      // 右子树地址（数组下标）
	int height;     // 当前结点为根的子树高度
	void Init() { data = key = left = right = height = -1; }
	void Init(int k_, int d_ = 0) { Init(); key = k_; data = d_; }
	Binary_tree_node() { Init(); }
	Binary_tree_node(int k_, int d_ = 0) { Init(k_, d_); }
};
Binary_tree_node tr[maxn];
int root, tp;  // root标记根节点位置，tp全局结点分配下标
inline int UpdateHeight(int now)
{
	// 更新 tr[now] 结点的子树高度，即tr[now].height的值
	int max_height = 0;
	if (tr[tr[now].left].height > tr[tr[now].right].height)
		max_height = tr[tr[now].left].height;
	if (tr[tr[now].left].height < tr[tr[now].right].height)
		max_height = tr[tr[now].right].height;
	
	return max_height + 1;
}
inline int HeightDiff(int now)
{
	// 计算 tr[now] 结点的平衡因子
	int height_diff = tr[tr[now].left].height - tr[tr[now].right].height;
	if (height_diff > 1)//L
	{
		if (tr[tr[now].left].right > tr[tr[now].left].left)//R
		{
			return LR_;
		}
		else
		{
			return LL_;
		}
	}
	else if (height_diff < -1)//R
	{
		if (tr[tr[now].right].left > tr[tr[now].right].right)//L
		{
			return RL_;
		}
		else
		{
			return RR_;
		}
	}
	return 0;
}
void L(int an)
{
	int E = an;
	int S = tr[an].right;
	int Eleft = tr[an].left;
	int Sleft = tr[tr[tr[an].right].left].key;
	int Sright = tr[tr[an].right].right;
	
	tr[an].left = tr[E].key;
	tr[an].key = tr[S].key;
	tr[an].right = tr[Sright].key;
	
	tr[tr[an].left].left = tr[Eleft].key;
	tr[tr[an].left].right = tr[Sleft].key;
	
	tr[an].height = max(tr[tr[an].left].height, tr[tr[an].right].height) + 1;
	tr[tr[an].left].height = max(tr[tr[tr[an].left].left].height, tr[tr[tr[an].left].right].height) + 1;
}
void R(int an)
{
	int S = an;
	int E = tr[an].left;
	int Sright = tr[an].right;
	int Eleft = tr[tr[an].left].left;
	int Eright = tr[tr[an].left].right;
	
	tr[an].key = E;
	tr[an].left = Eleft;
	tr[an].right = S;
	tr[tr[an].right].left = Eright;
	tr[tr[an].right].right = Sright;
	
	tr[an].height = max(tr[tr[an].left].height, tr[tr[an].right].height) + 1;
	tr[tr[an].right].height = max(tr[tr[tr[an].right].left].height, tr[tr[tr[an].right].left].height) + 1;
}
int LL(int an)
{
	R(an);
	return an;
}
int RR(int an)
{
	L(an);
	return an;
}
int LR(int an)
{
	L(tr[an].left);
	R(an);
	return an;
}
int RL(int an)
{
	R(tr[an].right);
	L(an);
	return an;
}
void Balance(int& now)
{
	int rotate_type = HeightDiff(now);
	switch (rotate_type)
	{
	case LL_:
		LL(now);
		break;
	case RR_:
		RR(now);
		break;
	case LR_:
		LR(now);
		break;
	case RL_:
		RL(now);
		break;
	default:
		;
	}
	
	tr[now].height = UpdateHeight(now);
}
void Insert(int& now, int key, int data = 0)
{
	if (now == -1)
	{
		// 传入指针为空，新建结点保存数据
		now = ++tp;
		tr[now].Init(key, data);
	}
	
	// 判断插入哪个子树，插入数据，判断平衡因子，做正确旋转，更新高度
	else if (key < tr[now].key)
	{
		Insert(tr[now].left, key);
	}
	else if (key > tr[now].key)
	{
		Insert(tr[now].right, key);
	}
	
	Balance(now);
}
void Delete(int& now, int key)
{
	if (now == -1) return;
	else if (key < tr[now].key) Delete(tr[now].left, key);
	else if (key > tr[now].key) Delete(tr[now].right, key);
	else
	{
		// 删除当前结点
		if (tr[now].left == -1 && tr[now].right == -1)
		{
			tr[now].key = -1;
		}
		else if (tr[now].left != -1 && tr[now].right == -1)
		{
			tr[now] = tr[tr[now].left];
		}
		else if (tr[now].left == -1 && tr[now].right != -1)
		{
			tr[now] = tr[tr[now].right];
		}
		else if (tr[now].left != -1 && tr[now].right != -1)
		{
			int prev = tr[now].left;
			int p_prev = now;
			while (tr[prev].right != -1)
			{
				p_prev = prev;
				prev = tr[prev].right;
			}
			tr[now].key = tr[prev].key;
			if (tr[now].left == prev)
			{
				tr[now].left = tr[prev].left;
				prev = -1;
			}
			if (prev != -1)
			{
				tr[p_prev].right = tr[prev].left;
				prev = -1;
			}
		}
	}
	// 处理树平衡
	Balance(now);
}
void InOrder_helper(int& now, int index)
{
	if (tr[now].key != -1)
	{
		InOrder_helper(tr[now].left, index);
		keys[index++] = tr[now].key;
		InOrder_helper(tr[now].right, index);
	}
}
int InOrder(int& now, int index, int k)
{
	InOrder_helper(now, index);
	int key = keys[k - 1];
	return key;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, op, key, data;
	while (cin >> n)
	{
		root = tp = -1;
		while (n--)  // 初始化根结点和“内存指针”
		{
			cin >> op;
			if (op == 1)//insert
			{
				cin >> key;
				Insert(root, key);
			}
			else if (op == 2)//delete
			{
				cin >> key;
				key = InOrder(root, 0, key);
				cout << key << endl;
				Delete(root, key);
			}
		}
		return 0;
	}
}
