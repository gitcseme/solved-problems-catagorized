#include <bits/stdc++.h>
using namespace std;

string leading(long long n, long long k) {
    double c = k * log10(n);
    c = c - floor(c);
    double lead = pow(10, c) * 1000;
    return to_string(lead).substr(0, 3);
}

long long bigmod(long long a, long long b, long long M) {
    if (b == 0)
        return 1 % M;
    long long x = bigmod(a, b/2, M);
    x = (x * x) % M;
    if (b % 2 == 1)
        x = (x * a) % M;
    return x;
}

int main() {
    //freopen("zzz.txt", "r", stdin);
    long long t, n, k;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld", &n, &k);
        printf("%s...%03d\n", leading(n, k).c_str(), bigmod(n, k, 1000));
    }

    return 0;
}
