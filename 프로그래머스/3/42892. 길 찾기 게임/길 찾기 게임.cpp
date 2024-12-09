#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

struct Treenode
{
	int val;
	pair<int, int> location;
	Treenode* left;
	Treenode* right;
	Treenode() : val(0), location({ -1,-1 }), left(nullptr), right(nullptr) {}
};


void preorder(Treenode* node, vector<int>& pre)
{
	if (!node) return;

	pre.push_back(node->val);
	preorder(node->left, pre);
	preorder(node->right, pre);
}
void postorder(Treenode* node, vector<int>& post)
{
	if (!node) return;

	postorder(node->left, post);
	postorder(node->right, post);
	post.push_back(node->val);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
	vector<vector<int>> answer(2);

	// 인덱스값 넣어주기
	for (int i{}; i < nodeinfo.size(); i++) 
	{
		nodeinfo[i].push_back(i + 1);
	}

	// x좌표 오름차순 정렬
	sort(nodeinfo.begin(), nodeinfo.end(), [](vector<int> a, vector<int> b)->bool {return a[0] < b[0]; });

	// 자신 앞,뒤 인덱스 연결해주기
	unordered_map<int, unordered_map<string, int>> um;
	for (int i{}; i < nodeinfo.size(); i++)
	{
		if (i - 1 >= 0)
		{
			um[nodeinfo[i][2]]["before"] = nodeinfo[i - 1][2];
		}
		else 
		{
			//없으면 -1
			um[nodeinfo[i][2]]["before"] = -1;
		}
		if (i + 1 < nodeinfo.size())
		{
			um[nodeinfo[i][2]]["next"] = nodeinfo[i + 1][2];
		}
		else 
		{
			um[nodeinfo[i][2]]["next"] = -1;
		}
	}

	//y좌표
	sort(nodeinfo.begin(), nodeinfo.end(), 
		[](vector<int>a, vector<int>b)->bool 
		{
			if (a[1] == b[1]) 
			{
				return a[0] < b[0];
			}
			else 
			{
				return a[1] > b[1];
			}
		}
	);
	queue<Treenode*> nodes;
	unordered_map<int, Treenode*> unordered_nodes;
	for (auto e : nodeinfo) 
	{
		Treenode* node = new Treenode;
		node->location = { e[0], e[1] };
		node->val = e[2];
		nodes.push(node);
		unordered_nodes[node->val] = node;
	}

	Treenode* root = nodes.front();
	um[root->val]["ismaked"] = true;
	nodes.pop();
	while (!nodes.empty()) 
	{
		Treenode* curnode = nodes.front();
		nodes.pop();
		
		int val{curnode->val};
		int next{};
		int before{};
		while (val > 0 && val < nodeinfo.size()+1)
		{
			val = um[val]["next"];
			if (um[val]["ismaked"])
			{
				next = val;
				break;
			}
		}
		val = curnode->val;
		while (val > 0 && val < nodeinfo.size() + 1)
		{
			val = um[val]["before"];
			if (um[val]["ismaked"])
			{
				before = val;
				break;
			}
		}

		val = curnode->val;
		if (next && before)
		{
			if (unordered_nodes[next]->location.second > unordered_nodes[before]->location.second)
			{
				unordered_nodes[before]->right = unordered_nodes[val];
			}
			else
			{
				unordered_nodes[next]->left = unordered_nodes[val];
			}
		}
		else if (next)
		{
			unordered_nodes[next]->left = unordered_nodes[val];
		}
		else if (before)
		{
			unordered_nodes[before]->right = unordered_nodes[val];
		}

		um[val]["ismaked"] = true;
	}

	preorder(root, answer[0]);
	postorder(root, answer[1]);
	return answer;
}

int main() 
{
	solution({ {5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2} });
}