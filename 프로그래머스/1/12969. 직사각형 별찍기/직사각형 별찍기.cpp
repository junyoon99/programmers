#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    
    for(int i{}; i < b; i++)
    {
        for(int j{}; j < a; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
    
    return 0;
}