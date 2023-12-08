#include<iostream>
#include<cstring>
#include<stack>
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
int countTree(TreeNode* root)
{
	if (root == NULL)
		return 0;
	int left, right;
	left = countTree(root->left);
	right = countTree(root->right);
	return right > left ? right + 1 : left + 1;
}
TreeNode* treeBuild(TreeNode*& root)
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
queue<TreeNode*>qe;
void treeLevel(TreeNode* root)
{
	bool status = 1;
	cout << root->val;
	qe.push(root);
	while (!qe.empty())
	{
		TreeNode* node = qe.front();
		if(status)
			status = 0;
		else
			cout << node->val;
		if (node->left)
			qe.push(node->left);
		if (node->right)
			qe.push(node->right);
		qe.pop();
	}
	cout << endl;
}
void treeInit()
{
	TreeNode* root = new TreeNode();
	treeBuild(root);
	treeLevel(root);
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
	Problem: 1067
	User: 202200201118
	Language: C++
	Result: AC
	Time:9 ms
	Memory:2356 kb
**********************************************************************/
