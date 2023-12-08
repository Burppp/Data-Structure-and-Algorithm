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
vector<int>nums1;
vector<int>nums2;
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
				if (idx == nums.size() - 1)
					node->right = new TreeNode(0);
				if (nums[idx] != 0)
					q.push(node->left);
			}
			idx++;
			//if (idx < n && nums[idx] != -1)
			if (idx < n)
			{
				node->right = new TreeNode(nums[idx]);
				if (nums[idx] != 0)
					q.push(node->right);
			}
			idx++;
		}
	}
	return root;
}
bool bianli(TreeNode* root, int flag)
{
	if (root == NULL)
		return false;
	switch (flag)
	{
	case 0://先序遍历
		if(root->val)
			cout << root->val << ' ';
		bianli(root->left, flag);
		bianli(root->right, flag);
		break;
	case 1://中序遍历
		bianli(root->left, flag);
		if (root->val)
			cout << root->val << ' ';
		bianli(root->right, flag);
		break;
	case 2:
		bianli(root->left, flag);
		bianli(root->right, flag);
		if (root->val)
			cout << root->val << ' ';
		break;
	}
	return true;
}
void treeMerge(TreeNode* &root1, TreeNode* &root2)
{
	if (!root1 && !root2)
		return;
	if (root1 == NULL && root2 != NULL)
		root1 = new TreeNode(0);
	if (root1 != NULL && root2 == NULL)
		root2 = new TreeNode(0);
	root1->val += root2->val;
	treeMerge(root1->left, root2->left);
	treeMerge(root1->right, root2->right);
}
void treeInit()
{
	int num;
	cin >> num;
	int n;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		nums1.push_back(n);
	}
	for (int i = 0; i < nums1.size(); i++)
		if (nums1[i] == -1)
			nums1[i] = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		nums2.push_back(n);
	}
	for (int i = 0; i < nums2.size(); i++)
		if (nums2[i] == -1)
			nums2[i] = 0;
	TreeNode* root1 = treeBuild(nums1);
	TreeNode* root2 = treeBuild(nums2);
	treeMerge(root1, root2);
	for (int i = 0; i < 3; i++)
	{
		bianli(root1, i);
		cout << endl;
	}
	cout << endl;
	nums1.erase(nums1.begin(), nums1.end());
	nums2.erase(nums2.begin(), nums2.end());
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
	Problem: 1173
	User: 202200201118
	Language: C++
	Result: AC
	Time:12 ms
	Memory:2224 kb
**********************************************************************/
