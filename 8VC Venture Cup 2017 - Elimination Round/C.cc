#include <cstdio>
#include <iostream>
using namespace std;

const int kMaxn = 10000 + 10;

int f[kMaxn];

int Findf(int x) {
    if(f[x] != x)
        f[x] = Findf(f[x]);
    return f[x];
} 

void Init(int n) {
    for(int i =1 ; i <= n; i++) 
        f[i] = i;
}

int main() {
    int n;
    cin >> n;
    Init(n);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
       int x;
       cin >> x;
       int f1 = Findf(i);
       int f2 = Findf(x);
       if(f1 != f2)
           f[f1] = f2;
    }
    for(int i = 1; i <= n; i++) 
        if(Findf(i) == i)
            cnt++;
    cout << cnt << endl;
    return 0;
}
