#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<int, pair<char, char>>mp;
class TreeNode
{
public:
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val('*'), left(nullptr), right(nullptr) {}
	TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(char x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Tree
{
public:
	TreeNode* root;
	int deep;
	int ld;
	int rd;
	char left_;
	char right_;
	int max;
	char cur;
	Tree()
	{
		deep = ld = rd = max = 0;
		left_ = right_ = 0;
		cur = 0;
		TreeNode* root = new TreeNode();
		treeBuild(root);
		maxDistance(root);
		int i, j, key = 0;
		map<int, pair<char, char>>ans;
		int max_ = mp.begin()->first;
		for (map<int, pair<char, char>>::iterator it = mp.begin(); it != mp.end(); it++)
			if (it->first > max_)
				key = it->first;
		cout << key << ':';
		if (key)
			cout << mp[key].first << ' ' << mp[key].second;
		cout << endl;
		mp.clear();
		ans.clear();
	}
	TreeNode* treeBuild(TreeNode*& root)
	{
		char init;
		cin >> init;
		if (init == '#')
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
	void countTree(TreeNode* root, int cmp)
	{
		if (!root)
			return;
		cmp++;
		if (!root->left && !root->right)
			if (deep < cmp || deep == cmp && root->val < cur)
				deep = cmp, cur = root->val;
		countTree(root->left, cmp);
		countTree(root->right, cmp);
	}
	void countLeft(TreeNode* root)
	{
		if (!root->left)
		{
			ld = 0;
			left_ = root->val;
			return;
		}
		root = root->left;
		countTree(root, 0);
		ld = deep;
		left_ = cur;
	}
	void countRight(TreeNode* root)
	{
		if (!root->right)
		{
			rd = 0;
			right_ = root->val;
			return;
		}
		root = root->right;
		countTree(root, 0);
		rd = deep;
		right_ = cur;
	}
	void maxDistance(TreeNode* root)
	{
		if (!root)
			return;
		deep = 0;
		countLeft(root);
		deep = 0;
		countRight(root);
		deep = 0;
		max = ld + rd;
		char temp;
		if (left_ > right_)
		{
			temp = left_;
			left_ = right_;
			right_ = temp;
		}
		if(mp.find(max) == mp.end())
		{
			mp[max].first = left_;
			mp[max].second = right_;
		}
		else
		{
			if (mp[max].first > left_ || (mp[max].first <= left_ && mp[max].second > right_))
			{
				mp[max].first = left_;
				mp[max].second = right_;
			}
		}
		maxDistance(root->left);
		maxDistance(root->right);
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
		Tree();
	return 0;
}
/**********************************************************************
	Problem: 1066
	User: 202200201118
	Language: C++
	Result: AC
	Time:13 ms
	Memory:2360 kb
**********************************************************************/
