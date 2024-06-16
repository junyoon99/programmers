#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    int n;
    cin >> str >> n;

    for (int i{}; i < n; i++)
    {
        std::cout << str;
    }
    return 0;
}