#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000005
int phi[MAXN];
int step[MAXN];
int sodf[MAXN];

void sieve_phi() {
    for (int i = 2; i < MAXN; ++i) phi[i] = i;
    for (int i = 2; i < MAXN; ++i)
        if (phi[i] == i)
            for (int j = i; j < MAXN; j += i)
                phi[j] -= phi[j] / i;

    sodf[1] = step[1] = 0;
    for (int i = 2; i < MAXN; ++i) {
        step[i] = 1 + step[phi[i]];
        sodf[i] = sodf[i-1] + step[i];
    }
}

int main() {
    sieve_phi();
    int t, m, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &m, &n);
        printf("%d\n", sodf[n] - sodf[m-1]);
    }

    return 0;
}
