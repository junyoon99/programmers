#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

void LowestCost(unordered_map<int, vector<pair<int, int>>>& roads, const int& n, const int& s, vector<int>& Price)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, s });
	Price[s] = 0;

	while (!pq.empty()) 
	{
		pair<int, int> here = pq.top();
		pq.pop();

		for (auto e : roads[here.second]) 
		{
			if (Price[e.second] > Price[here.second] + e.first) 
			{
				Price[e.second] = Price[here.second] + e.first;
				pq.push({ Price[e.second], e.second });
			}
		}
	}
}

int LowestCost(unordered_map<int, vector<pair<int, int>>>& roads, const int& n, const int& s, const int& goal)
{
	vector<int> Price(n + 1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, s });
	Price[s] = 0;

	while (!pq.empty())
	{
		pair<int, int> here = pq.top();
		pq.pop();

		for (auto e : roads[here.second])
		{
			if (Price[e.second] > Price[here.second] + e.first)
			{
				Price[e.second] = Price[here.second] + e.first;
				pq.push({ Price[e.second], e.second });
			}
		}
	}
	return Price[goal];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

	int answer = INT_MAX;
	unordered_map<int, vector<pair<int, int>>> roads;
	for (auto& e : fares)
	{
		//first가 요금, second가 도착하는 노드
		roads[e[0]].push_back({ e[2],e[1] });
		roads[e[1]].push_back({ e[2],e[0] });
	}

	vector<int> PriceAB(n + 1, INT_MAX);
	LowestCost(roads, n, s, PriceAB);
	vector<int> PriceA(n + 1, INT_MAX);
	LowestCost(roads, n, a, PriceA);
	vector<int> PriceB(n + 1, INT_MAX);
	LowestCost(roads, n, b, PriceB);

	queue<int> q;
	q.push(s);
	vector<int> vec;
	unordered_map<int, bool> check;
	while (!q.empty()) 
	{
		int front = q.front();
		q.pop();
		if (!check[front])
		{
			vec.push_back(front);
			check[front] = true;
			for (auto e : roads[front])
			{
				q.push(e.second);
			}
		}
	}

	for (auto e : vec)
	{
		answer = min(answer, PriceAB[e] + PriceA[e] + PriceB[e]);
	}

    return answer;
}

int main() 
{
	solution(6, 4, 6, 2, { {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} });
}