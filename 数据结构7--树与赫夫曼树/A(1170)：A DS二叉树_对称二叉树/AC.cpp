#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* before;
	TreeNode() : val(0), left(nullptr), right(nullptr), before(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), before(nullptr) {}
};
TreeNode* treeBuild(vector<int>& nums)
{
	if (nums.empty() || nums[0] == -1)
		return NULL;
	int n = nums.size();
	int idx = 0;
	TreeNode* root = new TreeNode(nums[idx++]);
	queue<TreeNode*> q;
	q.push(root);
	while (idx < n)
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			TreeNode* node = q.front();
			q.pop();
			//if (idx < n && nums[idx] != -1)
			if (idx < n)
			{
				node->left = new TreeNode(nums[idx]);
				if(nums[idx] != -1)
					q.push(node->left);
			}
			idx++;
			//if (idx < n && nums[idx] != -1)
			if (idx < n)
			{
				node->right = new TreeNode(nums[idx]);
				if (nums[idx] != -1)
					q.push(node->right);
			}
			idx++;
		}
	}
	return root;
}
stack<TreeNode*>stk;
int idx = 0;
queue<TreeNode*>qe;
void treeLevel(TreeNode* root, vector<int> &arr)
{
	bool status = 1;
	//cout << root->val << ' ';
	arr.push_back(root->val);
	qe.push(root);
	while (!qe.empty())
	{
		TreeNode* node = qe.front();
		if (status)
			status = 0;
		else
		{
			//cout << node->val << ' ';
			arr.push_back(node->val);
		}
		if (node->left)
			qe.push(node->left);
		if (node->right)
			qe.push(node->right);
		qe.pop();
	}
	//cout << endl;
}
string treeInit()
{
	int num;
	cin >> num;
	int n;
	vector<int>nums;
	vector<int>left_num;
	vector<int>right_num;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		nums.push_back(n);
	}
	if (num == 1 || num == 0)
		return "true";
	TreeNode* root = treeBuild(nums);
	idx = 0;
	if (!root->left)
		return "false";
	treeLevel(root->left, left_num);
	idx = 0;
	if (!root->right)
		return "false";
	treeLevel(root->right, right_num);
	if (left_num[0] != right_num[0])
		return "false";
	if (left_num.size() != right_num.size())
		return "false";
	int temp = 1;
	for (int i = 1; i < (left_num.size() - 1) / 2 + 1; i++, temp++)
		for (int j = 0; j < temp * 2; j++)
		{
			if (i + j >= left_num.size() || right_num.size() <= i + temp * 2 - j - 1)
				break;
			if (left_num[i + j] != right_num[i + temp * 2 - j - 1])
				return "false";
		}
	return "true";
}
int main()
{
	int t;
	cin >> t;
	while (t--)
		cout << treeInit() << endl;
	return 0;
}
/**********************************************************************
	Problem: 1170
	User: 202200201118
	Language: C++
	Result: AC
	Time:11 ms
	Memory:2224 kb
**********************************************************************/
