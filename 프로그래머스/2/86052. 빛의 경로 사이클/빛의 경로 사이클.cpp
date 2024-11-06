#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> grid) {
	vector<int> answer;
	unordered_map<string, vector<pair<int, int>>> um;
	unordered_map<string, bool> visited;

	int row{static_cast<int>(grid.size())};
	int col{static_cast<int>(grid[0].size())};
	for (int i{}; i < row; i++)
	{
		for (int j{}; j < col; j++)
		{
			um[to_string(i) + "and" + to_string(j)].push_back({i - 1, j});	//UP
			um[to_string(i) + "and" + to_string(j)].push_back({ i, j + 1 });	//RIGHT
			um[to_string(i) + "and" + to_string(j)].push_back({ i + 1, j });	//DOWN
			um[to_string(i) + "and" + to_string(j)].push_back({ i, j - 1 });	//LEFT
		}
	}

	for (int i{}; i < row; i++)
	{
		for (int j{}; j < col; j++)
		{
			for (int dir{}; dir < 4; dir++) 
			{
				string s{ to_string(i) + "and" + to_string(j) };
				string t{to_string(um[s][dir].first) + "and" + to_string(um[s][dir].second)};
				int count{};
				while (!visited[s + "to" + t])
				{
					visited[s + "to" + t] = true;
					count++;
					switch (grid[(um[s][dir].first + row)%row][(um[s][dir].second+col)%col])
					{
					case 'S':
						s = to_string((um[s][dir].first + row) % row) + "and" + to_string((um[s][dir].second + col) % col);
						t = to_string(um[s][dir].first) + "and" + to_string(um[s][dir].second);
						break;
					case 'L':
						s = to_string((um[s][dir].first + row) % row) + "and" + to_string((um[s][dir].second + col) % col);
						dir = (dir - 1 + 4) % 4;
						t = to_string(um[s][dir].first) + "and" + to_string(um[s][dir].second);
						break;
					case 'R':
						s = to_string((um[s][dir].first + row) % row) + "and" + to_string((um[s][dir].second + col) % col);
						dir = (dir + 1 + 4) % 4;
						t = to_string(um[s][dir].first) + "and" + to_string(um[s][dir].second);
						break;
					}
				}
				if (count) answer.push_back(count);
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}
