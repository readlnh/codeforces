#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;

const int kMaxn = 1000000 + 5;

ll sum[kMaxn << 2];


void Build(int root, int l, int r) {
    if(l == r) {
       sum[root] = 0;
       return;
    }
    int mid = (l + r) >> 1;
    Build(root << 1, l, mid);
    Build(root << 1|1, mid + 1, r);
    sum[root] = sum[root << 1] + sum[root << 1|1]; 
}

ll Query(int root, int l, int r, int L, int R) {
    if(L <= l && R >= r)
        return sum[root];
    int mid = (l + r) >> 1;
    ll ans = 0;
    if(L <= mid)
        ans += Query(root << 1, l, mid, L, R);
    if(R > mid)
        ans += Query(root << 1|1, mid + 1, r, L, R);
   return ans; 
}

void AddNode(int root, int l, int r, int pos) {
    if(l == r) {
        sum[root] = sum[root] + 1;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) 
        AddNode(root << 1, l, mid, pos);
    else 
        AddNode(root << 1|1, mid + 1, r, pos);
    sum[root] = sum[root << 1] + sum[root << 1|1];
}

int main() {
    int n,k;
    cin >> n >> k;
    if(k > n/2) 
        k = n - k;
    ll ans = 1;
    int now = 1;
    Build(1, 1, n);
    for(int i = 1; i <= n; i++) {
        int next = now + k;
        ll temp = 0;
        if(next > n + 1)
            temp = Query(1, 1, n, now + 1, n) + Query(1, 1, n, 1, next - n - 1);
        else 
            temp = Query(1, 1, n, now + 1, next - 1);
        ans = ans + temp + 1;
        cout << ans;
        if(i == n) cout << endl;
        else cout << " ";
        AddNode(1, 1, n, now);
        if(next > n) next = next - n;
        AddNode(1, 1, n, next);
        now = next;
    }
    return 0;
}
