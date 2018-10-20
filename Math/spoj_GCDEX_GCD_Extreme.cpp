#include <bits/stdc++.h>
using namespace std;

#define MAXN 4000001
int phi[MAXN];
long long cum[MAXN], res[MAXN];

void preCall() {
    phi[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if(!phi[i]) {
            for (int j = i; j < MAXN; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = (phi[j] / i) * (i-1);
            }
        }
    }

    for (int i = 1; i < MAXN; ++i)
        for (int j = i; j < MAXN; j += i)
            res[j] += 1LL * phi[j/i] * i;

    cum[0] = 0;
    for (int i = 1; i < MAXN; ++i)
        cum[i] = cum[i-1] + (res[i] - i); // as j = i+1.
}

int main () {
    preCall();
    int n;
    while (scanf("%d", &n) && n) {
        printf("%lld\n", cum[n]);
    }

    return 0;
}
