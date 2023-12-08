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
stack<TreeNode*>s1;
stack<int>s2;
void postOrder(TreeNode* root)
{
	int tag = 0;
	TreeNode* node = root;
	do
	{
		while (node)
		{
			tag = 0;
			s1.push(node);
			s2.push(tag);
			node = node->left;
		}
		if (!node)
		{
			if (!s2.top())
			{
				tag = 1;
				s2.top() = tag;
				node = s1.top()->right;
			}
			else
			{
				node = s1.top();
				s1.pop();
				s2.pop();
				cout << node->val;
				node = NULL;
			}
		}
	}while (!s1.empty());
	cout << endl;
}
void treeInit()
{
	TreeNode* root = new TreeNode();
	treeBuild(root);
	postOrder(root);
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
	Problem: 1068
	User: 202200201118
	Language: C++
	Result: AC
	Time:10 ms
	Memory:2356 kb
**********************************************************************/
