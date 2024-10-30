#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	vector<pair<int, pair<float, float>>> vec(N+2);
	priority_queue<int> q;
	for (auto& e : stages) 
	{
		q.push(e);
	}
	while (!q.empty()) 
	{
		int top{q.top()-1};
		q.pop();
		++vec[top].second.second;
	}
	int h{static_cast<int>(stages.size())};
	for (int i{}; i <= N; ++i) 
	{
		vec[i].first = i+1;
		vec[i].second.first = h;
		h -= vec[i].second.second;
	}
	vec.pop_back();
	vec.pop_back();
	sort(vec.begin(), vec.end(), [&](pair<int, pair<float, float>> a, pair<int, pair<float, float>> b) -> bool
		{
			float first{ a.second.first == 0 ? a.second.second == 0 ? 0 : 1 : a.second.second / a.second.first};
			float second{ b.second.first == 0 ? b.second.second == 0 ? 0 : 1 : b.second.second / b.second.first };
			if (first == second)
			{
				return a.first < b.first;
			}
			else
			{
				return first > second;
			}
		});
	for (auto e : vec) 
	{
		answer.push_back(e.first);
	}
	return answer;
}