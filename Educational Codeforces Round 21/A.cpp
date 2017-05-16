#include <cstdio>

int z(int x) {
    int ans = 1;
    int y = x;
    while(y >= 10) {
        y = y / 10;
        ans = ans * 10;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    int t = z(n);
    int ans = (n/t + 1) * t - n;
    if(n < 10)
        ans = 1;
    printf("%d\n", ans);
    return 0;
}
