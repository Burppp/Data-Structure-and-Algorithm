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
	Binary_tree_node(Binary_tree_node*& external_root)
	{
		data = external_root->data;
		left = external_root->left;
		right = external_root->right;
	}
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
	void Binary_tree_insert_helper(int data, Binary_tree_node*& external_root)
	{
		if (data > external_root->data)
		{
			if (external_root->right == NULL)
			{
				if(data != -1)
					external_root->right = new Binary_tree_node(data);
				else
					external_root->right = NULL;
				return;
			}
			else
				Binary_tree_insert_helper(data, external_root->right);
		}
		else
		{
			if (external_root->left == NULL)
			{
				if(data != -1)
					external_root->left = new Binary_tree_node(data);
				else
					external_root->left = NULL;
				return;
			}
			else
				Binary_tree_insert_helper(data, external_root->left);
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
		Binary_tree_insert_helper(data, root);
		return;
	}
	void Binary_tree_inorder_traversal_helper(Binary_tree_node*& external_root, vector<int> &output)
	{
		if (external_root != NULL)
		{
			Binary_tree_inorder_traversal_helper(external_root->left, output);
			//cout << external_root->data << ' ';
			output.push_back(external_root->data);
			Binary_tree_inorder_traversal_helper(external_root->right, output);
		}
	}
	void Binary_tree_inorder_traversal(int k)
	{
		vector<int>output;
		Binary_tree_inorder_traversal_helper(root, output);
		//cout << endl;
		cout << output[k] << endl;
	}
	void Binary_tree_delete_node_helper(int data, Binary_tree_node*& external_root)
	{
		if(external_root == NULL)
			return;
		if (data > external_root->data && external_root->right != NULL)
		{
			Binary_tree_delete_node_helper(data, external_root->right);
		}
		else if (data < external_root->data && external_root->left != NULL)
		{
			Binary_tree_delete_node_helper(data, external_root->left);
		}
		else if (data == external_root->data)
		{
			if (external_root->left == NULL && external_root->right == NULL)
			{
				delete external_root;
				external_root = NULL;
			}
			else if (external_root->left != NULL && external_root->right == NULL)
			{
				external_root = external_root->left;
				return;
			}
			else if (external_root->left == NULL && external_root->right != NULL)
			{
				external_root = external_root->right;
				return;
			}
			else if (external_root->left != NULL && external_root->right != NULL)
			{
				Binary_tree_node* prev = external_root->left;
				Binary_tree_node* p_prev = external_root;
				while (prev->right != NULL)
				{
					p_prev = prev;
					prev = prev->right;
				}
				external_root->data = prev->data;
				if (external_root->left == prev)
				{
					external_root->left = prev->left;
					delete prev;
					return;
				}
				p_prev->right = prev->left;
				delete prev;
				return;
			}
		}
	}
	void Binary_tree_delete_node(int data)
	{
		Binary_tree_delete_node_helper(data, root);
	}
	void Binary_tree_search_helper(int target, Binary_tree_node*& external_root, int& output, bool& get_result)
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
		if (get_result)
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
		vector<int>datas = vector<int>(num);
		for (int i = 0; i < num; i++)
			cin >> datas[i];
		cin >> num;
		Binary_tree* tree = new Binary_tree();
		tree->Binary_tree_build(datas);
		tree->Binary_tree_inorder_traversal(num - 1);
	}
	return 0;
}
/**********************************************************************
	Problem: 1166
	User: 202200201118
	Language: C++
	Result: AC
	Time:12 ms
	Memory:2224 kb
**********************************************************************/
