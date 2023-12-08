#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
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
bool bianli(TreeNode* root, int flag)
{
	if (root == NULL)
		return false;
	switch (flag)
	{
	case 0://先序遍历
		cout << root->val << ' ';
		bianli(root->left, flag);
		bianli(root->right, flag);
		break;
	case 1://中序遍历
		bianli(root->left, flag);
		cout << root->val << ' ';
		bianli(root->right, flag);
		break;
	case 2:
		bianli(root->left, flag);
		bianli(root->right, flag);
		cout << root->val << ' ';
		break;
	}
	return true;
}
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
            if (idx < n && nums[idx] != -1) 
			{
                node->left = new TreeNode(nums[idx]);
                q.push(node->left);
            }
            idx++;
            if (idx < n && nums[idx] != -1) 
			{
                node->right = new TreeNode(nums[idx]);
                q.push(node->right);
            }
            idx++;
        }
    }
    return root;
}
void treeInit()
{
	int num;
	cin >> num;
	int n;
	vector<int>nums;
	while (num--)
	{
		cin >> n;
		nums.push_back(n);
	}
	TreeNode* root = treeBuild(nums);
	for (int i = 0; i < 3; i++)
	{
		bianli(root, i);
		cout << endl;
	}
	cout << endl;
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
	Problem: 1169
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2224 kb
**********************************************************************/
