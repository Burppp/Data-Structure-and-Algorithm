#include<iostream>
using namespace std;
int tree_count = 0;
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
void treeLevel(TreeNode* root)
{
	TreeNode* arr[100];
	for (int i = 0;i < 100;i++)
		arr[i] = new TreeNode;
	bool status = 1;
	cout << root->val << ' ';
	//qe.push(root);
	arr[0] = root;
	int front, end;
	front = 0, end = 1;
	//while (!qe.empty())
	while (tree_count--)
	{
		//TreeNode* node = qe.front();
		TreeNode* node = arr[front];
		if (status)
			status = 0;
		else
			cout << node->val << ' ';
		if (node->left)
			//qe.push(node->left);
			arr[end++] = node->left;
		if (node->right)
			//qe.push(node->right);
			arr[end++] = node->right;
		//qe.pop();
		front++;
	}
}
TreeNode* treeBuild(TreeNode*& root)
{
	char init;
	cin >> init;
	if (init == '#')
		root = NULL;
	else
	{
		tree_count++;
		root = new TreeNode;
		root->val = init;
		treeBuild(root->left);
		treeBuild(root->right);
	}
	return root;
}
void treeReverse(TreeNode* root)
{
	if (!root)
		return;
	TreeNode* swap = root->right;
	root->right = root->left;
	root->left = swap;
	treeReverse(root->left);
	treeReverse(root->right);
}
void treeInit()
{
	tree_count = 0;
	TreeNode* root = new TreeNode();
	treeBuild(root);
	if (!root)
	{
		for (int i = 0;i < 4;i++)
			cout << "NULL" << endl;
		return;
	}
	treeReverse(root);
	for (int i = 0;i < 3;i++)
	{
		bianli(root, i);
		cout << endl;
	}
	treeLevel(root);
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
	Problem: 1069
	User: 202200201118
	Language: C++
	Result: AC
	Time:10 ms
	Memory:2352 kb
**********************************************************************/
