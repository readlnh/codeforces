#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int kMaxn = 50 + 5;
const int kInf = 0x1f1f1f1f;

int s[kMaxn], z[kMaxn], f[kMaxn];

int a[kMaxn];
bool vis[kMaxn];

int Min;

void Count(int i, int pos, int m, char c) {
    if(c >= '0' && c <= '9')
        s[i] = min(min(s[i], pos), min(s[i], m - pos));
    if(c >= 'a' && c <= 'z')
        z[i] = min(min(z[i], pos), min(z[i], m - pos));
    if(c =='#' || c == '*' || c == '&')
        f[i] = min(min(f[i], pos), min(f[i], m - pos));
}

void Dfs(int n, int deep) {
    //cout << n << " " << deep << endl;
    if(deep == 3 + 1) {
        //cout << a[1] << " " << a[2] << " " << a[3] << endl;
        int sum = s[a[1]] + z[a[2]] + f[a[3]];
        Min = min(Min, sum);
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            a[deep] = i;
            vis[i] = true;
            Dfs(n,deep + 1);
            vis[i] = false;
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    memset(s, kInf, sizeof(s));
    memset(z, kInf, sizeof(z));
    memset(f, kInf, sizeof(f));
    memset(vis, false, sizeof(vis));
    Min = kInf;
    for(int i = 1; i <= n; i++) {
        string ss;
        getchar();
        cin >> ss;
        for(int j = 0; j < m; j++)
           Count(i, j, m, ss[j]);
    }
    //for(int i = 1; i <= n; i++)
    //    cout << s[i] << " " << z[i] << " " << f[i] << endl;
    Dfs(n,1);
    cout << Min << endl;
    return 0;
}
