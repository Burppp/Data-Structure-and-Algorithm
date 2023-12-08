#include<iostream>
#include<cstring>
using namespace std;
class TreeNode 
{
public:
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(' '), left(nullptr), right(nullptr) {}
	TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(char x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
int leave_count = 0;
TreeNode* treeBuild(TreeNode* root, char cur)
{
	root->val = cur;
	char left, right;
	cin >> left;
	if (left != '0')
	{
		TreeNode* left_node = new TreeNode();
		root->left = left_node;
		treeBuild(left_node, left);
	}
	cin >> right;
	if (right != '0')
	{
		TreeNode* right_node = new TreeNode();
		root->right = right_node;
		treeBuild(right_node, right);
	}
	return root;
}
int leave(TreeNode* root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return leave(root->left) + leave(root->right);
}
void left_leave(TreeNode* root)
{
	if (root == NULL)
		return ;
	if (root != NULL)
	{
		if (root->left != NULL)
			if (root->left->left == NULL && root->left->right == NULL)
				leave_count++;
		left_leave(root->left);
		left_leave(root->right);
	}
	return;
}
void treeInit()
{
	TreeNode* root = new TreeNode();
	char init;
	cin >> init;
	if (init != '0')
		treeBuild(root, init);
	leave_count = 0;
	left_leave(root);
	cout << leave_count << endl;
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
	Problem: 1063
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2220 kb
**********************************************************************/
