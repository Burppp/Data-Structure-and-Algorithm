#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* before;
	TreeNode() : val(0), left(nullptr), right(nullptr), before(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), before(nullptr) {}
};
TreeNode* treeBuild(vector<int>& nums)
{
	if (nums.empty() || nums[0] == -1)
		return NULL;
	int n = nums.size();
	int idx = 0;
	TreeNode* root = new TreeNode(nums[idx++]);
	queue<TreeNode*> q;
	q.push(root);
	while (idx < n)
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			TreeNode* node = q.front();
			q.pop();
			if (idx < n && nums[idx] != -1)
			{
				node->left = new TreeNode(nums[idx]);
					q.push(node->left);
			}
			idx++;
			if (idx < n && nums[idx] != -1)
			{
				node->right = new TreeNode(nums[idx]);
					q.push(node->right);
			}
			idx++;
		}
	}
	return root;
}
stack<TreeNode*>stk;
int idx = 0;
queue<TreeNode*>qe;
void treeLevel(TreeNode* root, vector<int>& arr)
{
	bool status = 1;
	//cout << root->val << ' ';
	arr.push_back(root->val);
	qe.push(root);
	while (!qe.empty())
	{
		TreeNode* node = qe.front();
		if (status)
			status = 0;
		else
		{
			//cout << node->val << ' ';
			arr.push_back(node->val);
		}
		if (node->left)
			qe.push(node->left);
		if (node->right)
			qe.push(node->right);
		qe.pop();
	}
	//cout << endl;
}
int sum = 0;
vector<int> arr;
bool flag = 0;
bool status = 0;
int findPath(TreeNode* root, int target)
{
	if (!root->left && !root->right && root->val != -1)
	{
		flag = 1;
		int re = root->val;
		arr.push_back(root->val);
		sum += root->val;
		root->val = -1;
		return re;
	}
	int ans = 0;
	if(root->left)
	{
		findPath(root->left, target);
		if (flag)
		{
			arr.push_back(root->val);
			sum += root->val;
			return root->val;
		}
	}
	if(root->right)
	{
		findPath(root->right, target);
		if (flag)
		{
			arr.push_back(root->val);
			sum += root->val;
			return root->val;
		}
	}
 	sum += ans;
	if (!flag)
		root->val = -1;
	return sum;
}
void treeInit()
{
	int num, target;
	cin >> target >> num;
	int n;
	vector<int>nums;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		nums.push_back(n);
	}
	TreeNode* root = treeBuild(nums);
	status = 0;
	while(root->val != -1)
	{
		flag = 0;
		sum = 0;
		findPath(root, target);
		if (sum == target)
		{
			if (arr.size() != 1)
				for (int i = arr.size() - 1; i >= 0; i--)
					cout << arr[i] << ' ';
			else
				cout << arr[0];
			cout << endl;
			status = 1;
		}
		arr.erase(arr.begin(), arr.end());
	}
	if (!status)
		cout << "Path not found" << endl;
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
	Problem: 1171
	User: 202200201118
	Language: C++
	Result: AC
	Time:7 ms
	Memory:2224 kb
**********************************************************************/
