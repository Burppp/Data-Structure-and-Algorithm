#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(-1), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
TreeNode* treeBuild(vector<int> &mid, vector<int> &end, int size)
{
	if (size == 0)
		return NULL;
	TreeNode* node = new TreeNode;
	node->val = end[size - 1];
	int i = 0;
	while (mid[i] != end[size - 1])
		i++;
	node->left = treeBuild(mid, end, i);
	vector<int> from_mid(mid.begin() + i + 1, mid.end());
	vector<int> from_end(end.begin() + i, end.end());
	node->right = treeBuild(from_mid, from_end, size - i - 1);
	return node;
}
void find(TreeNode* root, int& min)
{
	if (!root)
		return;
	if (!root->left && !root->right)
		if (root->val < min)
			min = root->val;
	find(root->left, min);
	find(root->right,min);
}
void treeInit()
{
	int i;
	int num;
	cin >> num;
	vector<int> mid, end;
	int temp;
	for (i = 0;i < num;i++)
	{
		cin >> temp;
		mid.push_back(temp);
	}
	for (i = 0;i < num;i++)
	{
		cin >> temp;
		end.push_back(temp);
	}
	TreeNode* root = treeBuild(mid, end, mid.size());
	int min = INT_MAX;
	find(root, min);
	cout << min << endl;
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
	Problem: 1070
	User: 202200201118
	Language: C++
	Result: AC
	Time:413 ms
	Memory:5068 kb
**********************************************************************/
