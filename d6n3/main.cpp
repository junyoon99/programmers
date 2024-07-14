#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
	string answer = "";
	for (int e{}; e < numLog.size()-1; e++)
	{
		switch (numLog[e + 1] - numLog[e])
		{
		case 1: answer += 'w'; break;
		case -1: answer += 's'; break;
		case 10: answer += 'd'; break;
		case -10: answer += 'a'; break;
		}
	}
	return answer;
}