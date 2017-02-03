#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int kMaxn = 1e4 + 10;

bool f[kMaxn];

int main() {
    int n,m,z;
    cin >> n >> m >> z;
    memset(f, false, sizeof(f));
    int x = n;
    while(x <= z) {
        f[x] = true;
        x += n;
    }
    int ans = 0;
    x = m;
    while(x <= z) {
        if(f[x]) ans++;
        x += m;
    }
    cout << ans << endl;
}
