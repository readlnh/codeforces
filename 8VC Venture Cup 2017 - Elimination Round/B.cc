#include <cstdio>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;

map<string, bool>g1,g2;

string p[1000 + 5];
string e[1000 + 5];

queue<string>que;

int main() {
    int n,m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        g1[p[i]] = true;
    }
    for(int i = 1; i <= m; i++) {
        cin >> e[i];
        if(g1[e[i]])
            cnt++;
    }
    n = n - cnt;
    m = m - cnt;
    if(cnt % 2 == 1)
        m--;
    if(n > m)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    return 0;
}
