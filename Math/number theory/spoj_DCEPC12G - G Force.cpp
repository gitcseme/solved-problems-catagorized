#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000000 + 2
const int M = 1000000000 + 7;
int phi[MAXN];
int prime[MAXN];
int F[MAXN];
bool mark[MAXN];

int bigmod(int a, int b) {
    if (b == 0)
        return 1 % M;
    int x = bigmod(a, b/2);
    x = (x * x) % M;
    if (b & 1) x = (x * a) % M;
    return x;
}

int fact(int n) {
    int f = 1;
    for (int i = 1; i <= n; ++i) f = f * i;
    return f;
}

void preCall() {
    for(int i = 2; i < MAXN; ++i) {
        if (!mark[i]) {
            phi[i] = i-1;
            for (int j = i + i; j < MAXN; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = (phi[j]/i) * (i-1);
                mark[j] = true;
            }
        }
    }
    phi[1] = 1; prime[1] = 0; F[1] = 0;
    for (int i = 2; i < MAXN; ++i) {
        prime[i] = !mark[i] ? prime[i-1] + 1 : prime[i-1];
        F[i] = (prime[i] <= phi[i]) ? 0 : prime[i] - phi[i];
    }
}

int main() {
    preCall();

    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", bigmod(phi[n], fact(F[n])));
    }

    return 0;
}
