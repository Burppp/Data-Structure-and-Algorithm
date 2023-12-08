#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>
#include <queue>
#include <map>
using namespace std;
class treeNode
{
public:
	bool tag;
	string info;
	vector<treeNode*>next;
	vector<int>length;
	treeNode() :tag(0), info("") {}
	treeNode(string i) :tag(0), info(i) {}
	void info_init(string i)
	{
		info = i;
	}
};
int nodes_num = -1;
int edges_num = -1;
map<string, int>mp_nodes;
vector<pair<string, string>>ans_info;
vector<unsigned>ans_length;
vector<treeNode* >area;
void treeBuild(treeNode**& nodes, map<string, int>mp_nodes)
{
	cin >> edges_num;
	for (int i = 0; i < edges_num; i++)
	{
		string left, right;
		int length;
		cin >> left >> right >> length;
		nodes[mp_nodes[left]]->next.push_back(nodes[mp_nodes[right]]);
		nodes[mp_nodes[right]]->next.push_back(nodes[mp_nodes[left]]);
		nodes[mp_nodes[left]]->length.push_back(length);
		nodes[mp_nodes[right]]->length.push_back(length);
	}
}
void prim(treeNode**& nodes, int cur)
{
	unsigned int which_node = 0;
	unsigned int which_edge = 0;
	static int length_sum = 0;
	int min;
	for (int i = 0; i < nodes_num - 1; i++)
	{
		nodes[cur]->tag = 1;
		area.push_back(nodes[cur]);//已有的节点范围
		min = INT_MAX;
		for (which_node = 0; which_node < area.size(); which_node++)
			for (which_edge = 0; which_edge < area[which_node]->length.size(); which_edge++)
				if (min > area[which_node]->length[which_edge] && !area[which_node]->next[which_edge]->tag)
					min = area[which_node]->length[which_edge];
		for (which_node = 0; which_node < area.size(); which_node++)//
		{
			for (which_edge = 0; which_edge < area[which_node]->length.size(); which_edge++)
				if (min == area[which_node]->length[which_edge] && !area[which_node]->next[which_edge]->tag)
					break;
			if (which_edge != area[which_node]->length.size())
				break;
		}
		int cur_next = mp_nodes[area[which_node]->next[which_edge]->info];
		ans_info.push_back({ area[which_node]->info, nodes[cur_next]->info });
		ans_length.push_back(area[which_node]->length[which_edge]);
		cur = cur_next;
	}
	for (int i = 0; i < nodes_num - 1; i++)
		length_sum += ans_length[i];
	cout << length_sum << endl;
	cout << "prim:" << endl;
	for (int i = 0; i < nodes_num - 1; i++)
		cout << ans_info[i].first << ' ' << ans_info[i].second << ' ' << ans_length[i] << endl;
	ans_info.erase(ans_info.begin(), ans_info.end());
	ans_length.erase(ans_length.begin(), ans_length.end());
	area.erase(area.begin(), area.end());
	for (int i = 0; i < nodes_num - 1; i++)
		nodes[i]->tag = 0;
}
bool search_loop(treeNode **&nodes, int which_node, int which_edge)
{
	treeNode* cur = nodes[which_node];
	treeNode* side1 = cur, * side2 = nodes[which_node]->next[which_edge];
	int mark = -1;
	for (int i = 0; i < ans_info.size(); i++)
	{
		if (i == mark)
		{
			mark = -1;
			continue;
		}
		if (cur->info == nodes[which_node]->next[which_edge]->info)
			return true;
		if ((side1->info == ans_info[i].first && side2->info == ans_info[i].second) || (side1->info == ans_info[i].second && side2->info == ans_info[i].first))
			return true;
		if (cur->info == ans_info[i].first)
		{
			cur = nodes[mp_nodes[ans_info[i].second]];
			mark = i;
			i = -1;
			continue;
		}
		if (cur->info == ans_info[i].second)
		{
			cur = nodes[mp_nodes[ans_info[i].first]];
			mark = i;
			i = -1;
		}
	}
	if (cur->info == nodes[which_node]->next[which_edge]->info)
		return true;
	return false;
}
void kruskal(treeNode**& nodes)
{
	int t = nodes_num;
	int min;
	int which_node, which_edge;
	while(t-- - 1)
	{
		min = INT_MAX;
		for (which_node = 0; which_node < nodes_num - 1; which_node++)
			for (which_edge = 0; which_edge < nodes[which_node]->next.size(); which_edge++)
				if (nodes[which_node]->length[which_edge] < min)//
				{
					if(nodes[which_node]->tag == 0 || nodes[which_node]->next[which_edge]->tag == 0)
						min = nodes[which_node]->length[which_edge];
					if (nodes[which_node]->tag && nodes[which_node]->next[which_edge]->tag && !search_loop(nodes, which_node, which_edge))
						min = nodes[which_node]->length[which_edge];
				}
		for (which_node = 0; which_node < nodes_num - 1; which_node++)
		{
			for (which_edge = 0; which_edge < nodes[which_node]->next.size(); which_edge++)
				if (nodes[which_node]->length[which_edge] == min && !search_loop(nodes,which_node,which_edge))
					break;
			if (which_edge != nodes[which_node]->next.size())
				break;
		}
		if (!nodes[which_node]->tag)
		{
			nodes[which_node]->tag = 1;
			area.push_back(nodes[which_node]);
		}
		nodes[which_node]->next[which_edge]->tag = 1;
		area.push_back(nodes[which_node]->next[which_edge]);
		if(mp_nodes[nodes[which_node]->info] < mp_nodes[nodes[which_node]->next[which_edge]->info])
			ans_info.push_back({ nodes[which_node]->info, nodes[which_node]->next[which_edge]->info });
		else
			ans_info.push_back({ nodes[which_node]->next[which_edge]->info, nodes[which_node]->info });
		ans_length.push_back(nodes[which_node]->length[which_edge]);
	}
	cout << "kruskal:" << endl;
	for (int i = 0; i < ans_info.size(); i++)
		cout << ans_info[i].first << ' ' << ans_info[i].second << ' ' << ans_length[i] << endl;
}
int main()
{
	cin >> nodes_num;
	string* p = new string[nodes_num];
	treeNode** nodes = new treeNode * [nodes_num];
	for (int i = 0; i < nodes_num; i++)
	{
		cin >> p[i];
		nodes[i] = new treeNode(p[i]);
		mp_nodes[p[i]] = i;
	}
	treeBuild(nodes, mp_nodes);
	string start;
	cin >> start;
	prim(nodes, mp_nodes[start]);
	kruskal(nodes);
	return 0;
}
/**********************************************************************
	Problem: 1016
	User: 202200201118
	Language: C++
	Result: AC
	Time:13 ms
	Memory:2240 kb
**********************************************************************/
