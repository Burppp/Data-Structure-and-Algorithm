#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
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
TreeNode* treeBuild(TreeNode* root, char cur, int num)
{
	root->val = cur;
	char left, right;
	cin >> left;
	if (left != '0')
	{
		TreeNode* left_node = new TreeNode(left);
		root->left = left_node;
		treeBuild(left_node, left, num);
	}
	cin >> right;
	if (right != '0')
	{
		TreeNode* right_node = new TreeNode(right);
		root->right = right_node;
		treeBuild(right_node, right, num);
	}
	return root;
}
void array_tree(int i, int* v, int num)
{
	if (i <= num && v[i])
	{
		cout << v[i] << ' ';
		array_tree(2 * i, v, num);
		array_tree(2 * i + 1, v, num);
	}
}
//void treeInit(int num)
//{
//	TreeNode* root = new TreeNode();
//	char init;
//	cin >> init;
//	if (init != '0')
//	{
//		treeBuild(root, init, num);
//		init_num = 0;
//		bianli(root, 0);
//		cout << endl;
//	}
//}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int num;
		cin >> num;
		int* p = new int[num + 1];
		for (int i = 1;i <= num;i++)
			cin >> p[i];
		array_tree(1, p, num);
		cout << endl;
	}
	return 0;
}
/**********************************************************************
	Problem: 1065
	User: 202200201118
	Language: C++
	Result: AC
	Time:6 ms
	Memory:2220 kb
**********************************************************************/
