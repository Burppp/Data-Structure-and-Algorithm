#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
class TreeNode
{
public:
	int val;
	int deep;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :deep(0), val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :deep(0), val(x), left(nullptr), right(nullptr) {}
};
bool compare_node(const TreeNode* p1, const TreeNode* p2)
{
	return p1->val < p2->val;
}
bool compare_int(int p1, int p2)
{
	return p1 < p2;
}
void swap_node(TreeNode*& node1, TreeNode*& node2)
{
	TreeNode* temp = node1;
	node1 = node2;
	node2 = temp;
}
void swap_int(int& p1, int& p2)
{
	int v = p1;
	p1 = p2;
	p2 = v;
}
TreeNode* treeBuild(vector<TreeNode*>& nums)
{
	TreeNode* root = new TreeNode();
	TreeNode** _new = new TreeNode * [nums.size() + 1];
	for (int i = 0;i < nums.size();i++)
		_new[i] = new TreeNode();
	int idx = 0;
	do
	{
		TreeNode* left = new TreeNode();
		TreeNode* right = new TreeNode();
		left = nums[0]->val > nums[1]->val ? nums[1] : nums[0];
		right = nums[0]->val > nums[1]->val ? nums[0] : nums[1];
		_new[idx]->left = left;
		_new[idx]->right = right;
		_new[idx]->val = _new[idx]->left->val + _new[idx]->right->val;
		nums.erase(nums.begin(), nums.begin() + 2);
		nums.push_back(_new[idx]);
		//sort(nums.begin(), nums.end(), compare_node);
		for (int i = 0;i < nums.size();i++)
			for (int j = i + 1;j < nums.size();j++)
				if (!compare_node(nums[i], nums[j]))
				{
					swap_node(nums[i], nums[j]);
				}
		for (int i = 0;i < nums.size();i++)
			for (int j = i + 1;j < nums.size();j++)
				if (nums[i]->val == nums[j]->val && nums[i]->left != NULL && nums[j]->left == NULL)
					swap_node(nums[i], nums[j]);
		root = _new[idx];
		idx++;
	} while (nums.size() != 1);
	return root;
}
vector<int>* code = NULL;
int idx = 0;
void treeCoding(TreeNode* root, int flag)
{
	if (!root->left && !root->right)
	{
		code[idx].push_back(root->val);
		idx++;
		return;
	}
	code[idx].push_back(0);
	treeCoding(root->left, 0);
	code[idx].assign(code[idx - 1].begin(), code[idx - 1].begin() + root->deep - 1);
	code[idx].push_back(1);
	treeCoding(root->right, 1);
}
void treeDeep(TreeNode* root, int dp)
{
	if (root)
	{
		root->deep = dp;
		treeDeep(root->left, dp + 1);
		treeDeep(root->right, dp + 1);
	}
	return;
}
void treePrint(vector<int>& arr, vector<int>*& code)
{
	for (int count = 0;count < arr.size();count++)
	{
		for (int i = 0;i < arr.size();i++)
		{
			if (arr[count] == code[i].back())
			{
				cout << code[i].back() << '-';
				for (int j = 0;j < code[i].size() - 1;j++)
					cout << code[i][j];
				cout << endl;
				code[i].back() = -1;
				break;
			}
		}
	}
}
vector<int>arr;
vector<int>arr_orin;
vector<TreeNode*>node;
void treeInit()
{
	int num = 0;
	int n = 0;
	cin >> num;
	code = new vector<int>[num];
	for (int i = 0;i < num;i++)
	{
		cin >> n;
		arr.push_back(n);
	}
	for (int i = 0;i < arr.size();i++)
		arr_orin.push_back(arr[i]);
	//sort(arr.begin(), arr.end());
	for (int i = 0;i < arr.size();i++)
		for (int j = i;j < arr.size();j++)
			if (!compare_int(arr[i], arr[j]))
				swap_int(arr[i], arr[j]);
	for (int i = 0;i < arr.size();i++)
	{
		TreeNode* cur = new TreeNode(arr[i]);
		node.push_back(cur);
	}
	TreeNode* root = new TreeNode();
	root = treeBuild(node);
	treeDeep(root, 1);
	treeCoding(root, 1);
	treePrint(arr_orin, code);
	idx = 0;
	arr.erase(arr.begin(), arr.end());
	arr_orin.erase(arr_orin.begin(), arr_orin.end());
	node.erase(node.begin(), node.end());
	for (int i = 0;i < num;i++)
		code[i].erase(code[i].begin(), code[i].end());
}
int main()
{
	int t = 0;
	cin >> t;
	while (t--)
		treeInit();
	cout << endl;
	return 0;
}
/**********************************************************************
	Problem: 1050
	User: 202200201118
	Language: C++
	Result: AC
	Time:33 ms
	Memory:2488 kb
**********************************************************************/
