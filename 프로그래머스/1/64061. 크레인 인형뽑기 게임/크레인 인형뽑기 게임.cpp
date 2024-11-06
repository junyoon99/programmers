#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> vec;

    for (auto e : moves)
    {
        e--;
        for (int i{}; i < static_cast<int>(board.size()); i++)
        {
            if (board[i][e])
            {
                int j = board[i][e];
                board[i][e] = 0;
                vec.push_back(j);
                if (vec.size() > 1) 
                {
                    if (vec.back() == *(vec.end() - 2)) 
                    {
                        vec.pop_back();
                        vec.pop_back();
                        answer += 2;
                    }
                }
                break;
            }
        }
    }
    
    return answer;
}