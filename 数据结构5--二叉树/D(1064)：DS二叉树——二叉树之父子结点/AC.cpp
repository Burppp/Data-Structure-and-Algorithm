#include<iostream>
#include<cstring>
#include<queue>
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
queue<char>fa;
queue<char>son;
bool bianli(TreeNode* root, int flag)
{
	if (root == NULL)
		return false;
	switch (flag)
	{
	case 0://先序遍历
		cout << root->val;
		bianli(root->left, flag);
		bianli(root->right, flag);
		break;
	case 1://中序遍历
		bianli(root->left, flag);
		cout << root->val;
		bianli(root->right, flag);
		break;
	case 2:
		bianli(root->left, flag);
		bianli(root->right, flag);
		cout << root->val;
		break;
	}
	return true;
}
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
		return;
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
void father_son(TreeNode* root)
{
	if (root == NULL)
		return;
	if (root != NULL)
	{
		if (root->left)
			if (root->left->left == NULL && root->left->right == NULL)
				fa.push(root->val);
		if (root->left == NULL && root->right == NULL)
			son.push(root->val);
		else
		{
			father_son(root->left);
			father_son(root->right);
		}
		if (root->right)
			if (root->right->left == NULL && root->right->right == NULL)
				fa.push(root->val);
	}
}
void treeInit()
{
	TreeNode* root = new TreeNode();
	char init;
	cin >> init;
	if (init != '0')
		treeBuild(root, init);
	//leave_count = 0;
	//left_leave(root);
	//cout << leave_count << endl;
	//for (int i = 0; i < 3; i++)
	//{
	//	bianli(root, i);
	//	cout << endl;
	//}
	if (root->left == NULL && root->right == NULL)
	{
		cout << root->val << ' ' << endl << root->val << ' ' << endl;
		return ;
	}
	father_son(root);
	while (!son.empty())
	{
		cout << son.front() << ' ';
		son.pop();
	}
	cout << endl;
	while (!fa.empty())
	{
		cout << fa.front() << ' ';
		fa.pop();
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
	Problem: 1064
	User: 202200201118
	Language: C++
	Result: AC
	Time:5 ms
	Memory:2224 kb
**********************************************************************/
