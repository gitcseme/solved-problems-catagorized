#include <bits/stdc++.h>
using namespace std;

long long  phi(long long n) {
    long long ret = n;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            ret -= ret / p;
        }
    }
    if (n > 1) ret -= ret / n;
    return ret;
}

int main() {
    long long n;
    while(scanf("%lld", &n) && n) {
        if (n == 1)
            printf("0\n");
        else
            printf("%lld\n", phi(n));
    }

    return 0;
}
