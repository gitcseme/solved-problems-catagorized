#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000 + 5
int phi[MAXN];
long long cum[MAXN];

void preCall() {
    for (int i = 2; i < MAXN; ++i) {
        if (!phi[i]) {
            for (int j = i; j < MAXN; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = (phi[j] / i) * (i-1);
            }
        }
    }
    cum[1] = 0;
    for (int i = 2; i < MAXN; ++i) cum[i] = cum[i-1] + phi[i];
}

int main () {
    preCall();
    int n;
    while (scanf("%d", &n) && n) {
        printf("%lld\n", cum[n]);
    }

    return 0;
}
