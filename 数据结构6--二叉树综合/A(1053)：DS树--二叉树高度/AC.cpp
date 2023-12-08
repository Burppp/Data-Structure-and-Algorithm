#include<iostream>
#include<cstring>
#include<stack>
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
int countTree(TreeNode* root)
{
	if (root == NULL)
		return 0;
	int left, right;
	left = countTree(root->left);
	right = countTree(root->right);
	return right > left ? right + 1 : left + 1;
}
TreeNode* treeBuild(TreeNode* &root)
{
	char init;
	cin >> init;
	if (init == '0')
		root = NULL;
	else
	{
		root = new TreeNode;
		root->val = init;
		treeBuild(root->left);
		treeBuild(root->right);
	}
	return root;
}
void treeInit()
{
	TreeNode* root = new TreeNode();
	treeBuild(root);
	cout << countTree(root) << endl;
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
	Problem: 1053
	User: 202200201118
	Language: C++
	Result: AC
	Time:9 ms
	Memory:2224 kb
**********************************************************************/
