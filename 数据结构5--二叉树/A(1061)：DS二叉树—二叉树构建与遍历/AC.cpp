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
TreeNode* treeBuild(TreeNode* root, char cur);
//bool bianli(TreeNode* root, int flag);
void first(TreeNode* root)
{
	if (root == NULL)
		return;
	cout << root->val;
	first(root->left);
	first(root->right);
}
void mid(TreeNode* root)
{
	if (root == NULL)
		return;
	mid(root->left);
	cout << root->val;
	mid(root->right);
}
void back(TreeNode* root)
{
	if (root == NULL)
		return;
	back(root->left);
	back(root->right);
	cout << root->val;
}
void treeInit()
{
	TreeNode* root = new TreeNode();
	char init;
	cin >> init;
	if (init != '#')
		treeBuild(root, init);
	//for (int i = 0; i < 3; i++)
	//{
	//	bianli(root, i);
	//	cout << endl;
	//}
	first(root);
	cout << endl;
	mid(root);
	cout << endl;

	back(root);
	cout << endl;

}
TreeNode* treeBuild(TreeNode* root, char cur)
{
	root->val = cur;
	char left, right;
	cin >> left;
	if(left != '#')
	{
		TreeNode* left_node = new TreeNode();
		root->left = left_node;
		treeBuild(left_node, left);
	}
	cin >> right;
	if(right != '#')
	{
		TreeNode* right_node = new TreeNode();
		root->right = right_node;
		treeBuild(right_node, right);
	}
	return root;
}
//bool bianli(TreeNode* root, int flag)
//{
//	if (root == NULL)
//		return false;
//	switch (flag)
//	{
//	case 0://先序遍历
//		cout << root->val;
//		bianli(root->left, flag);
//		bianli(root->right, flag);
//		break;
//	case 1://中序遍历
//		bianli(root->left, flag);
//		cout << root->val;
//		bianli(root->right, flag);
//		break;
//	case 2:
//		bianli(root->left, flag);
//		bianli(root->right, flag);
//		cout << root->val;
//		break;
//	}
//}
int main()
{
	int t;
	cin >> t;
	while (t--)
		treeInit();
	return 0;
}
/**********************************************************************
	Problem: 1061
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2224 kb
**********************************************************************/
