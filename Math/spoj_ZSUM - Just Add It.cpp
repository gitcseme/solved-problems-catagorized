#include <bits/stdc++.h>
using namespace std;

const int M = 10000007;

long long bigmod(long long a, long long b) {
    if (b == 0)
        return 1 % M;
    long long x = bigmod(a, b/2);
    x = (x * x) % M;
    if (b & 1) x = (x * a) % M;
    return x;
}

int main () {
    freopen("zzz.txt", "r", stdin);
    int t;
    long long n, k, s1, s2, s3, s4, ans;

    while (1) {
        scanf("%lld %lld", &n, &k);
        if (n==0 && k==0)
            break;
        s1 = (2 * bigmod(n-1, k)) % M;
        s2 = (2 * bigmod(n-1, n-1)) % M;
        s3 = bigmod(n, k);
        s4 = bigmod(n, n);
        ans = ((s1 + s2)%M + (s3 + s4)%M) % M;
        printf("%lld\n", ans);
    }

    return 0;
}
