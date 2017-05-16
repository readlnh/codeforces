#include <cstdio>
#include <cstring>
#include <map>
#define ll long long
using namespace std;

const int kMaxn = 100000 + 5;

ll a[kMaxn];
ll s[kMaxn];

map<ll, int> f1;
map<ll, int> f2;

int main() {
    int n;
    ll sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
        s[i] = sum;
        f2[a[i]]++;
    }
    if(sum % 2 != 0) {
        printf("NO\n");
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        f1[a[i]]++;
        f2[a[i]]--;
        ll p2 = sum - s[i];
        ll p1 = s[i];
        //printf("%lld %lld\n", p1, p2);
        if(p1 == p2) {
            printf("YES\n");
            return 0;
        }
        if(p1 > p2 && (p1 - p2) % 2 == 0) {
            if(f1[(p1 - p2) / 2] > 0) {
                printf("YES\n");
                return 0;
            }
        }
        else if(p2 > p1 && (p2 - p1) % 2 == 0) {
            if(f2[(p2 - p1) / 2] > 0) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
