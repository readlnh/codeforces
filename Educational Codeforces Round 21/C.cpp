#include <iostream>
#include <algorithm>
using namespace std;

struct aa {
    int id;
    int v;
    int now;
};

bool cmp1(aa x, aa y) {
    return x.v > y.v;
}

bool cmp2(aa x, aa y) {
    return x.id < y.id;
}

aa a[100 + 10];

int main() {
    int n,w;
    cin >> n >> w;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].v;
        a[i].id = i;
        a[i].now = (a[i].v + 1) / 2;
        w = w - a[i].now;
        if(w < 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    sort(a + 1, a + 1 + n, cmp1);
    for(int i = 1; i <= n; i++) {
        int res = a[i].v - a[i].now;
        if(w >= res) {
            w = w - res;
            a[i].now += res;
        }
        else {
            a[i].now += w;
            w = 0;
            break;
        }
    }
    sort(a + 1, a + 1 + n, cmp2);
    for(int i = 1; i <= n; i++) {
        cout << a[i].now << " ";
    }
    return 0;
}
