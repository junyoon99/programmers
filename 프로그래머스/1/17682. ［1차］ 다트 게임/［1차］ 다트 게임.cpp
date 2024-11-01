#include <string>
#include <unordered_map>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult) {
	int answer = 0;

	vector<int> vec;
	int cur{-1};
	string temp{};
	for (auto e : dartResult)
	{
		if (e >= '0' && e <= '9')
		{
			temp += e;
		}
		else
		{
			if (!temp.empty()) 
			{
				++cur;
				vec.push_back(stoi(temp));
				temp.clear();
			}
			switch (e)
			{
			case 'S':
				break;
			case 'D':
				vec[cur] = pow(vec[cur], 2);
				break;
			case 'T':
				vec[cur] = pow(vec[cur], 3);
				break;
			case '*':
				vec[cur] *= 2;
				if (cur != 0) 
				{
					vec[cur - 1] *= 2;
				}
				break;
			case '#':
				vec[cur] *= -1;
				break;
			}
		}
	}
	for (auto e : vec) 
	{
		answer += e;
	}
	return answer;
}