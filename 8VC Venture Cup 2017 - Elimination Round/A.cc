#include <cstdio>
#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

const int kMaxn = 1000000 + 10;

ll su[kMaxn],cnt;
bool isprime[kMaxn];

void Prime() {
    cnt = 1;
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for(ll i = 2; i <= 1000000 + 5; i++) {
        if(isprime[i]) 
            su[cnt++] = i;
        for(ll j = 1; j < cnt && su[j] * i < 1000000 + 5; j++) {
            isprime[su[j] * i] = false;
        }
    } 
}

int main() {
    Prime();
    int n;
    cin >> n;
    for(int i = 1; i <= 1000; i++) {
        if(!isprime[n*i + 1]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
