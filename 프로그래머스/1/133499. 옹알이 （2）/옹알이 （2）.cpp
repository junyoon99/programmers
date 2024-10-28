#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> babbling) {
	vector<string> words{ "aya","ye","woo","ma" };
	int answer = 0;
  for (auto f : babbling) 
  {
	  int before{ -1 };
	  for (int i{}; i < words.size(); ++i)
	  {
		  if (f.substr(0, words[i].size()) == words[i] && i != before)
		  {
			  f.erase(f.begin(), f.begin() + words[i].size());
			  before = i;
			  i = -1;
		  }
		  if (f.empty()) 
		  {
			  answer++;
			  break;
		  }
	  }
  }
	return answer;
}