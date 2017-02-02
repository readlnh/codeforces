#include <cstdio>
#include <iostream>
using namespace std;

const int kMaxn = 1e5 + 10;
const int kInf = 1e9 + 10;

int a[kMaxn], b[kMaxn], c[kMaxn], p[kMaxn], pos[kMaxn];

int main() {
    int n,l,r;
    scanf("%d %d %d", &n, &l, &r);
    for(int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) 
        scanf("%d", &p[i]), pos[p[i]] = i;
    int lower = -kInf;
    for(int i = 1; i <= n; i++) {
        int x = pos[i];
        int temp = max(l, a[x] + lower + 1);
        if(temp > r) {
            printf("-1\n");
            return 0;
        }
        b[x] = temp;
        lower = b[x] - a[x];
    }
    for(int i = 1; i < n; i++) 
        printf("%d ", b[i]);
    printf("%d\n", b[n]);
    return 0;
}

