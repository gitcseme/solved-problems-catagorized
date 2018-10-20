#include <bits/stdc++.h>
using namespace std;

long long bigmod(long long a, long long b, long long M) {
    if (b == 0)
        return 1 % M;
    long long x = bigmod(a, b/2, M);
    x = (x * x) % M;
    if (b & 1) x = (x * a) % M;
    return x;
}

int main () {
    int t;
    long long a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", bigmod(a, b, 10));
    }

    return 0;
}
