#include <iostream>
using namespace std;

const int kMaxn = 50 + 5;

int k[kMaxn],s[kMaxn],a[kMaxn];

int dis(int a, int b, int l) {
    if(a >= b)
        return a - b;
    else 
        return a + l - b;
}

int main() {
    int n,l;
    cin >> n >> l;
    for(int i = 1; i <= n; i++)
       cin >> a[i];
    for(int i = 1; i < n; i++)
       k[i] = dis(a[i + 1], a[i], l); 
    k[n] = dis(a[1], a[n], l);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++)
       s[i] = dis(a[i + 1], a[i], l); 
    s[n] = dis(a[1], a[n], l);
    int pos = 1;
    bool flag = false;
    for(pos = 1; pos <= n; pos++) {
        if(k[pos] == s[1]) {
            flag = true;
            for(int i = 1; i <= n; i++) {
                //cout << s[i] << "," << k[((i + pos - 1) - 1) % n  + 1] << endl;
                if(s[i] != k[((i + pos - 1) - 1) % n + 1]) {
                    flag = false;
                    break;
                }
            }
            if(flag) break;
        }
    }
    if(flag)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    return 0;
}
