#include <iostream>
#include <fstream>
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
	{
		max_height = tr[tr[now].left].height;
	}
	if (tr[tr[now].left].height < tr[tr[now].right].height)
	{
		max_height = tr[tr[now].right].height;
	}
	tr[now].height = max_height + 1;
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
void L(int& an)
{
	int anRight = tr[an].right;
	tr[an].right = tr[anRight].left;
	tr[anRight].left = an;
	an = anRight;
	UpdateHeight(tr[an].left);
	UpdateHeight(an);
}
void R(int& an)
{
	int anLeft = tr[an].left;
	tr[an].left = tr[anLeft].right;
	tr[anLeft].right = an;
	an = anLeft;
	UpdateHeight(tr[an].right);
	UpdateHeight(an);
}
int LL(int& an)
{
	R(an);
	return an;
}
int RR(int& an)
{
	L(an);
	return an;
}
int LR(int& an)
{
	L(tr[an].left);
	R(an);
	return an;
}
int RL(int& an)
{
	R(tr[an].right);
	L(an);
	return an;
}
void Balance(int& now)
{
	if(now == -1)
	{
		return;
	}
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
	
	UpdateHeight(now);
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
int Search(int prev, int &now)
{
	int p_prev;
	if(tr[now].left == -1)
	{
		p_prev = now;
		tr[prev].left = tr[now].right;
	}
	else
	{
		p_prev = Search(now,tr[now].left);
		Balance(now);
	}
	return p_prev;
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
			now = -1;
		}
		else if (tr[now].left != -1 && tr[now].right == -1)
		{
			now = tr[now].left;
		}
		else if (tr[now].left == -1 && tr[now].right != -1)
		{
			now = tr[now].right;
		}
		else if (tr[now].left != -1 && tr[now].right != -1)
		{
			int nowLeft = tr[now].left;
			int nowRight = tr[now].right;
			now = Search(nowRight, nowRight);
			if(now != nowRight)
			{
				tr[now].right = nowRight;
			}
			tr[now].left = nowLeft;
		}
	}
	// 处理树平衡
	Balance(now);
}
int index = 0;
void InOrder_helper(int& now)
{
	if (now != -1)
	{
		InOrder_helper(tr[now].left);
		keys[index++] = tr[now].key;
		InOrder_helper(tr[now].right);
	}
}
int InOrder(int& now, int k)
{
	if(now == -1)
	{
		return -1;
	}
	index = 0;
	InOrder_helper(now);
	if (k > index + 1)
	{
		return -1;
	}
	int key = keys[k - 1];
	return key;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fstream fin, fout;
	fin.open("test.in", ios::in);
	fout.open("test.out", ios::out);
	int n, op, key, data;
	while (fin >> n)
//	while (cin >> n)
	{
		root = tp = -1;
		while (n--)  // 初始化根结点和“内存指针”
		{
			fin >> op;
//			cin >> op;
			if (op == 1)//insert
			{
				fin >> key;
//				cin >> key;
				Insert(root, key);
			}
			else if (op == 2)//delete
			{
				fin >> key;
//				cin >> key;
				key = InOrder(root, key);
				fout << key << endl;
//				cout << key << endl;
				Delete(root, key);
			}
		}
		fin.close();
		fout.close();
		return 0;
	}
}