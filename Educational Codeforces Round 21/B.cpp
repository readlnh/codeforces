#include <cstdio>

const int kMaxn = 2 * 1e5 + 10;

double s[kMaxn];

int main() {
    int n,k;
    scanf("%d %d", &n, &k);
    s[0] = 0;
    for(int i = 1; i <= n; i++) {
        double x;
        scanf("%lf", &x);
        s[i] = s[i - 1] + x;
    }
    double ans = 0;
    for(int i = k; i <= n; i++)
        ans += (s[i] - s[i - k]);
    printf("%lf\n", ans /(double)(n -k + 1));
    return 0;
}
