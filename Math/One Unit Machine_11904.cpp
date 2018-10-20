#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007LL;
long long F[1000007];

long long bigmod(long long a, long long b) {
    if (b == 0)
        return 1 % mod;
    long long x = bigmod(a, b/2);
    x = (x * x) % mod;
    if (b & 1) x = (x * a) % mod;
    return x;
}

int main() {
    //freopen("zzz.txt", "r", stdin);
    F[0] = 1;
    for (long long i = 1; i <= 1000000; ++i)
        F[i] = (F[i - 1] * i) % mod;

    int t, n, x, cse = 0;
    long long ans, s;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        s = 0;
        ans = 1;
        while (n--) {
            scanf("%d", &x);
            ans = (ans * F[s+x-1]) % mod;
            ans = (ans * bigmod(F[s], mod-2)) % mod;
            ans = (ans * bigmod(F[x-1], mod-2)) % mod;

            s = s + x;
        }
        printf("Case %d: %lld\n", ++cse, ans);
    }

    return 0;
}
