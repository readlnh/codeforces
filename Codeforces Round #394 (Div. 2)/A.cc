#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    if(a == 0 && b == 0) {
        cout << "NO" << endl;
        return 0;
    }
    int c = abs(a - b);
    if(c == 1 || c == 0)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    return 0;
}
