#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<int, unordered_map<int, bool>> rotate90(unordered_map<int, unordered_map<int, bool>> key_map, int keysize)
{
	unordered_map<int, unordered_map<int, bool>> result;
	for (auto e : key_map) 
	{
		for (auto f : e.second) 
		{
			result[f.first][keysize - e.first] = true;
		}
	}
	return result;
}

bool iscando(unordered_map<int, unordered_map<int, bool>> key_map, unordered_map<int, unordered_map<int, bool>> lock_map, pair<int, int>& HowMuchMove, int locksize, int holescount)
{
	for (auto e : key_map) 
	{
		for (auto f : e.second) 
		{
			pair<int, int> location{ e.first + HowMuchMove.first, f.first + HowMuchMove.second};

			if (location.first >= 0 && location.first < locksize && location.second >= 0 && location.second < locksize)
			{
				if (lock_map.find(location.first) == lock_map.end())
				{
					return false;
				}
				else
				{
					if (lock_map[location.first].find(location.second) == lock_map[location.first].end()) 
					{
						return false;
					}
					else 
					{
						holescount--;
					}
				}
			}
		}
	}
	return holescount < 1 ? true : false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) 
{
	bool answer = false;

	unordered_map<int, unordered_map<int, bool>> key_map;
	unordered_map<int, unordered_map<int, bool>> lock_map;
	int locksize{static_cast<int>(lock.size())};
	int keysize{static_cast<int>(key.size())};
	for (int i{}; i < key.size(); i++)
	{
		for (int j{}; j < key[0].size(); j++)
		{
			if (key[i][j] == 1)
			{
				key_map[i][j] = true;
			}
		}
	}

	int holescount{};
	for (int i{}; i < lock.size(); i++)
	{
		for (int j{}; j < lock[0].size(); j++)
		{
			if (lock[i][j] == 0)
			{
				lock_map[i][j] = true;
				holescount++;
			}
		}
	}

	if (!holescount) 
	{
		return true;
	}

	for (int i{}; i < 4; i++) 
	{
		for (auto e : lock_map)
		{
			for (auto f : key_map)
			{
				for (auto g : e.second) 
				{
					for (auto h : f.second) 
					{
						pair<int, int> HowMuchMove{ e.first - f.first, g.first - h.first};
						if (iscando(key_map, lock_map, HowMuchMove, locksize, holescount))
						{
							return true;
						}
					}
				}
			}
		}
		key_map = rotate90(key_map, keysize-1);
	}

	return answer;
}