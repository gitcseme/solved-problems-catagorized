#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005
int phi[MAXN];

void sieve_phi() {
    for (int i = 1; i <= MAXN; ++i) phi[i] = i;
    for (int i = 2; i <= MAXN; ++i)
        if (phi[i] == i)
            for (int j = i; j <= MAXN; j += i)
                phi[j] -= phi[j] / i;
}

int main() {
    sieve_phi();
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", phi[n]);
    }

    return 0;
}
