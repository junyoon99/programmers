#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string str1, string str2) {
	string answer;
	int s1{};
	int s2{};

	for (int i{}; i < str1.size() + str2.size(); i++)
	{
		if (i % 2)
		{
			answer += str2[s2];
			s2++;
		}
		else
		{
			answer += str1[s1];
			s1++;
		}
	}
	return answer;
}

int main() 
{
	std::cout << solution("aaaaa", "bbbbb");
}