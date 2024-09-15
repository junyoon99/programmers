using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    for(long long i{price}; i <= price * count; i += price)
    {
        answer += i;
    }
    if(answer - money < 0) return 0;
    return answer - money;
}