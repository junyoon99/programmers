#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int min_r{ (int)wallpaper.size() };
    int max_r{};
    int min_c{ (int)wallpaper[0].size() };
    int max_c{};
    for (int i{}; i < (int)wallpaper.size(); i++)
    {
        for (int j{}; j < (int)wallpaper[i].size(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                if (min_r > i) min_r = i;
                if (max_r < i) max_r = i;
                if (min_c > j) min_c = j;
                if (max_c < j) max_c = j;
            }
        }
    }
    answer.push_back(min_r);
    answer.push_back(min_c);
    answer.push_back(max_r+1);
    answer.push_back(max_c+1);
    return answer;
}