#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000 + 5
long long phi[MAXN];
long long ans[MAXN];

void preCall() {
    for (int i = 1; i < MAXN; ++i) phi[i] = i;
    for (int i = 2; i < MAXN; ++i)
        if (phi[i] == i)
            for(int j = i; j < MAXN; j += i)
                phi[j] -= phi[j] / i;

    for (int i = 1; i < MAXN; ++i)
        for (int j = i; j < MAXN; j += i)
            ans[j] += ( phi[i] * i );
}

int main() {
    preCall();

    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        long long res = ans[n] + 1;
        res = (res * n) / 2;
        printf("%lld\n", res);
    }

    return 0;
}
