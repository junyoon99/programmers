#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for (int i{}; i < str.length(); i++)
    {
        if ((str[i] > 64) && (str[i] < 91)) cout << char(str[i] + 32);
        else if ((str[i] > 96) && (str[i] < 123)) cout << char(str[i] - 32);
    }
    return 0;
}