#include <cstdio>
#include <cstring>

const int kMaxn = 1e5 + 10;

int cnt[kMaxn],u[kMaxn],v[kMaxn],color[kMaxn];

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n - 1; i++) 
        scanf("%d %d", &u[i], &v[i]);
    for(int i = 1; i <= n; i++) 
        scanf("%d", &color[i]);
    for(int i = 1; i <= n - 1; i++) {
        if(color[u[i]] != color[v[i]]) {
            cnt[u[i]]++;
            cnt[v[i]]++;
            sum++;
        }
    }
    for(int i = 1; i <= n; i++) 
        if(cnt[i] == sum) {
            printf("YES\n");
            printf("%d\n", i);
            return 0;
        }
    printf("NO\n");
    return 0;
}
