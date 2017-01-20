#include <iostream>
#define ll long long
using namespace std;

const int kMaxn = 100 + 5;

ll a[kMaxn][kMaxn];

int main() {
    ll n,m,k,x,y;
    cin >> n >> m >> k >> x >> y;
    ll T = (2*n - 2) * m;
    if(n == 1) T = m;
    for(int i = 2; i <= n - 1; i++) 
        for(int j = 1; j <= m; j++)
            a[i][j] = k / T * 2;
    for(int i = 1; i <= m ; i++)
        a[1][i] = a[n][i] = k / T;
    k = k % T;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(k > 0)
                a[i][j]++,k--;
    for(int i = n - 1; i >= 1; i--) 
        for(int j = 1; j <= m; j++)
            if(k > 0)
                a[i][j]++,k--;
    ll Max = a[1][1];
    ll Min = a[1][1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            Max = max(Max, a[i][j]),Min = min(Min, a[i][j]);
    cout << Max << " " << Min << " " << a[x][y] << endl;
    return 0;
}
