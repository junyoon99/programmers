#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {

	for (int i{}; i < overwrite_string.size(); i++)
	{
		my_string[i + s] = overwrite_string[i];
	}

	string answer = my_string;
	return answer;
}

int main()
{
	solution("He11oWor1d", "lloWorl", 2);
	solution("Program29b8UYP", "merS123", 7);
}