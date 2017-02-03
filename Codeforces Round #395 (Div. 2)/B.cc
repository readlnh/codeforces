#include <cstdio>
#include <iostream>
using namespace std;

const int kMaxn = 2*1e5 + 10;

int a[kMaxn];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int mid = n / 2 + n % 2;
    for(int i = 1; i <= mid; i++)
        if(i % 2 == 1)
            swap(a[i], a[n - i + 1]);
    for(int i = 1; i < n; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[n]);
    return 0;
}
