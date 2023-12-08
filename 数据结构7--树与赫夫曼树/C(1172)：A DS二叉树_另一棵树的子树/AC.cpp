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
				if(nums[idx] != -1)
					q.push(node->right);
			}
			idx++;
		}
	}
	return root;
}
void bianli(TreeNode* root, vector<int> &preOrder)
{
	if (root == NULL)
		return ;
	preOrder.push_back(root->val);
	bianli(root->left, preOrder);
	bianli(root->right, preOrder);
}
string treeCompare(TreeNode* root1, TreeNode* root2)
{
	vector<int>preOrder1;
	vector<int>preOrder2;
	bianli(root1, preOrder1);
	bianli(root2, preOrder2);
	int i, j;
	for (i = 0;i < preOrder1.size();i++)
	{
		bool flag = 1;
		if (preOrder1[i] != preOrder2[0])
			continue;
		if (preOrder2.size() == 1 && i == preOrder1.size() - 1)
			return "true";
		for (j = 1;j < preOrder2.size() && i + j < preOrder1.size();j++)// 
		{
			flag = 0;
			if (preOrder1[i + j] != preOrder2[j])
				break;
		}
		if (!flag && j == preOrder2.size() || (i + j == preOrder1.size() && preOrder1[i + j - 1] == -1))// 
			return "true";
	}
	if (i == preOrder1.size())
		return "false";
}
void treeInit()
{
	int num;
	cin >> num;
	int n;
	vector<int>nums;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		nums.push_back(n);
	}
	TreeNode* root1 = treeBuild(nums);
	nums.erase(nums.begin(), nums.end());
	cin >> num;
	for (int i = 0;i < num;i++)
	{
		cin >> n;
		nums.push_back(n);
	}
	TreeNode* root2 = treeBuild(nums);
	cout << treeCompare(root1, root2) << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
		treeInit();
	return 0;
}
/**********************************************************************
	Problem: 1172
	User: 202200201118
	Language: C++
	Result: AC
	Time:11 ms
	Memory:2224 kb
**********************************************************************/
