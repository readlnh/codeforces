#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int Max = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum += x;
        Max = max(x, Max);
    }
    cout << Max * n - sum << endl;
}
