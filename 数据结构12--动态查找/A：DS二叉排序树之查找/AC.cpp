#include <iostream>
#include <vector>
using namespace std;
class Binary_tree_node
{
public:
	int data;
	Binary_tree_node* left, * right;
	Binary_tree_node() : left(NULL), right(NULL) {}
	Binary_tree_node(int e) : data(e), left(NULL), right(NULL) {}
};
class Binary_tree
{
public:
	Binary_tree_node* root;
	
	Binary_tree() : root(NULL) {}
	Binary_tree(int data)
	{
		root = new Binary_tree_node(data);
	}
	void Binary_tree_inset_helper(int data, Binary_tree_node*& external_root)
	{
		if (data > external_root->data)
		{
			if (external_root->right == NULL)
			{
				external_root->right = new Binary_tree_node(data);
				return;
			}
			else
				Binary_tree_inset_helper(data, external_root->right);
		}
		else
		{
			if (external_root->left == NULL)
			{
				external_root->left = new Binary_tree_node(data);
				return;
			}
			else
				Binary_tree_inset_helper(data, external_root->left);
		}
		return;
	}
	void Binary_tree_insert(int data)
	{
		if (root == NULL)
		{
			root = new Binary_tree_node(data);
			return;
		}
		Binary_tree_inset_helper(data, root);
		return;
	}
	void Binary_tree_inorder_traversal_helper(Binary_tree_node*& external_root)
	{
		if (external_root != NULL)
		{
			Binary_tree_inorder_traversal_helper(external_root->left);
			cout << external_root->data << ' ';
			Binary_tree_inorder_traversal_helper(external_root->right);
		}
	}
	void Binary_tree_inorder_traversal()
	{
		Binary_tree_inorder_traversal_helper(root);
	}
	void Binary_tree_search_helper(int target, Binary_tree_node*& external_root, int& output, bool &get_result)
	{
		if (target > external_root->data && external_root->right != NULL)
		{
			output++;
			Binary_tree_search_helper(target, external_root->right, output, get_result);
		}
		else if (target < external_root->data && external_root->left != NULL)
		{
			output++;
			Binary_tree_search_helper(target, external_root->left, output, get_result);
		}
		else if (target == external_root->data)
		{
			output++;
			get_result = true;
			return;
		}
		return;
	}
	int Binary_tree_search(int target)
	{
		int result = 0;
		bool get_result = false;
		Binary_tree_search_helper(target, root, result, get_result);
		if(get_result)
			return result;
		else
			return -1;
	}
	void Binary_tree_build(vector<int> datas)
	{
		int size = datas.size();
		for (int i = 0; i < size; i++)
			Binary_tree_insert(datas[i]);
		return;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int num;
		cin >> num;
		vector<int> datas = vector<int>(num);
		for (int i = 0; i < num; i++)
			cin >> datas[i];
		Binary_tree* tree = new Binary_tree;
		tree->Binary_tree_build(datas);
		tree->Binary_tree_inorder_traversal();
		cout << endl;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			int target;
			cin >> target;
			int result = tree->Binary_tree_search(target);
			cout << result << endl;
		}
	}
	return 0;
}
/**********************************************************************
	Problem: 1040
	User: 202200201118
	Language: C++
	Result: AC
	Time:24 ms
	Memory:2224 kb
**********************************************************************/
