#include <vector>
#include <cmath>
using namespace std;

bool IsCanIt(long long SetTime, int GoldGoal, int SilverGoal, vector<int> g, vector<int> s, vector<int> w, vector<int> t)
{
	long long MaxGold = 0;
	long long MaxSilver = 0;
	long long MaxTotal = 0;

	for (int i{}; i < t.size(); i++) 
	{
		long long TransportCount = (SetTime - t[i]) / (t[i] * 2) + 1;
		TransportCount -= (TransportCount % 1);
		long long CanCarryMax = TransportCount * w[i];

		MaxGold += min(static_cast<long long>(g[i]), CanCarryMax);
		MaxSilver += min(static_cast<long long>(s[i]), CanCarryMax);
		MaxTotal += min(static_cast<long long>(g[i] + s[i]), CanCarryMax);
	}

	if (MaxGold >= GoldGoal && MaxSilver >= SilverGoal && MaxTotal >= GoldGoal + SilverGoal)
	{
		return true;
	}
	return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) 
{
	long long answer = -1;
	long long TimeMax = pow(10, 15);
	long long TimeMin = 0;

	while (TimeMin < TimeMax) 
	{
		long long SetTime = (TimeMax + TimeMin) / 2;

		if (IsCanIt(SetTime, a, b, g, s, w, t)) 
		{
			answer = SetTime;
			TimeMax = SetTime;
		}
		else 
		{
			TimeMin = SetTime + 1;
		}
	}
	return answer;
}