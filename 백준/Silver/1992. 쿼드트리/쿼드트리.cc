#include <vector>
#include <string>
#include <iostream>
using namespace std;

void asdf(int y,int x, int size, vector<vector<int>>& video, string& answer)
{
	if (size == 1) 
	{
		answer += to_string(video[y][x]);
		return;
	} 
	answer += '(';
	for (int i{}; i < size; i += size/2) 
	{
		for (int j{}; j < size; j += size/2) 
		{
			int base{ video[y + i][x + j] };
			bool isfalse{};
			for (int k{}; k < size / 2; k++)
			{
				for (int l{}; l < size / 2; l++)
				{
					if (video[y + i + k][x + j + l] != base)
					{
						asdf(y+i,x+j, size / 2, video, answer);
						isfalse = true;
						break;
					}
				}
				if (isfalse) break;
			}
			if (!isfalse) answer += to_string(base);
		}
	}
	answer += ')';
}

string solution(int N, vector<vector<int>>& video) 
{
	string answer;
	asdf(0,0, N, video, answer);
	if (answer == "(1111)") answer = '1';
	if (answer == "(0000)") answer = '0';
	return answer;
}

int main() 
{
	int N;
	cin >> N;
	vector<vector<int>> video(N);

	for (int i{}; i < N; i++) 
	{
		string part{};
		cin >> part;
		for (auto e : part) 
		{
			video[i].push_back(e - '0');
		}
	}
	cout << solution(N, video);
}