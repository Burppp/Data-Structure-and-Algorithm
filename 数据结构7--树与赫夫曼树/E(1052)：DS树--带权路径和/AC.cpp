#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class TreeNode
{
public:
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val('#'), left(nullptr), right(nullptr) {}
	TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};
vector<int>power1;
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
int deep = 0;
int idx = 0;
int sum = 0;
int treePath(TreeNode* root)
{
	deep++;
	if (!root)
	{
		deep--;
		return sum;
	}
	if (!root->left && !root->right)
	{
		sum += (deep - 1)*power1[idx++];
		deep--;
		return sum;
	}
	treePath(root->left);
	treePath(root->right);
	deep--;
	return sum;
}
void treeInit()
{
	int num;
	int m;
	char init;
	cin >> init;
	TreeNode* root = new TreeNode();
	treeBuild(root, init);
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> m;
		power1.push_back(m);
	}
	deep = sum = idx = 0;
	cout << treePath(root) << endl;
	power1.erase(power1.begin(), power1.end());
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
	Problem: 1052
	User: 202200201118
	Language: C++
	Result: AC
	Time:14 ms
	Memory:2220 kb
**********************************************************************/
