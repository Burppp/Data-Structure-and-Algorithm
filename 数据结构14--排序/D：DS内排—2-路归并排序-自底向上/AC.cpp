#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
class trie;
string str;
string substr;
queue<trie*> qe;
class trie
{
public:
	char data;
	vector<trie*>child;
	trie(char ch) :data(ch) {}
	void Insert();
	void Insert_helper(trie* root, unsigned index);
	void Level_traversal();
	void Search();
	void Search_helper(trie* root, unsigned index);
	void DFS(trie* root, int& leaves);
};
void trie::Insert_helper(trie* root, unsigned index)
{
	int pos = 0;
	if (index == str.size())
		return;
	for (unsigned i = 0;i < root->child.size();i++)
	{
		if (str[index] == root->child[i]->data)
		{
			Insert_helper(root->child[i], index + 1);
			return;
		}
		else if (root->child[i]->data < str[index])
			pos++;
	}
	trie* insert_node = new trie(str[index]);
	root->child.insert(root->child.begin() + pos, insert_node);
	Insert_helper(root->child[root->child.size() - 1], index + 1);
	return;
}
void trie::Insert()
{
	Insert_helper(this, 0);
}
void trie::Level_traversal()
{
	qe.push(this);
	while (!qe.empty())
	{
		trie* cur_level = qe.front();
		qe.pop();
		if (cur_level->data != '#')
			cout << cur_level->data;
		for (unsigned i = 0;i < cur_level->child.size();i++)
			qe.push(cur_level->child[i]);
	}
}
void trie::DFS(trie* root, int& leaves)
{
	if (root->child.empty())
		leaves++;
	for (unsigned i = 0;i < root->child.size();i++)
		DFS(root->child[i], leaves);
}
int flag = 0;
void trie::Search_helper(trie* root, unsigned index)
{
	if (!root)
		return;
	if (index == substr.size())
	{
		int result = 0;
		DFS(root, result);
		cout << result << endl;
		flag = 1;
		return;
	}
	for (unsigned i = 0;i < root->child.size();i++)
		if (root->child[i]->data == substr[index])
		{
			Search_helper(root->child[i], index + 1);
			return;
		}
	if(flag == 0)
		cout << 0 << endl;
}
void trie::Search()
{
	flag = 0;
	Search_helper(this, 0);
}
int main()
{
	trie* root = new trie('#');
	while (cin >> str)
	{
		root->Insert();
		if (cin.get() == '\n')
			break;
	}
	root->Level_traversal();
	cout << endl;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> substr;
		root->Search();
	}
	return 0;
}
