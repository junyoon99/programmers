#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
	int answer = 0;

	unordered_map<string, unordered_map<string, int>> stat;
	string temp{};

	for (auto e : gifts) 
	{
		int here{};
		for (int i{}; e[i] != ' '; i++) 
		{
			temp.push_back(e[i]);
			here = i + 2;
		}
		string f = e.substr(here, e.size());
		stat[temp][f+"give"]++;
		stat[f][temp + "get"]++;
		temp.clear();
	}

	for (auto e : friends) 
	{
		int get{};
		int give{};
		for (auto names : friends)
		{
			get += stat[e][names + "get"];
			give += stat[e][names + "give"];
		}
		stat[e][e + "index"] = give - get;
	}

	for (auto e : friends) 
	{
		for (auto r : friends) 
		{
			if (e == r) continue;
			if (stat[e][r + "give"] > stat[r][e + "give"]) 
			{
				stat[e][e + "count"]++;
			}
			else if (stat[e][r + "give"] == stat[r][e + "give"]) 
			{
				if (stat[e][e + "index"] > stat[r][r + "index"]) 
				{
					stat[e][e + "count"]++;
				}
			}
		}
	}

	for (auto e : friends) 
	{
		answer = max(stat[e][e + "count"], answer);
	}
	return answer;
}