#include <bits/stdc++.h>
using namespace std;

template <typename T, typename I>
T gcd (T a, I b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main () {
    int n;
    long long lcm, ans, q, d_q, d_div, r, g;
    while (scanf("%d", &n) != EOF) {
        lcm = 1;
        for (int i = 1; i <= n; ++i) {
            lcm = ( (lcm * i) / gcd(lcm, i) );
        }
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = ans + (lcm / i);
        }
        ans = ans * n;

        if (ans % lcm == 0)
            printf("%lld\n", (ans/lcm));
        else {
            q = ans / lcm;
            d_q = log10(q) + 1;

            r = ans % lcm;
            g = gcd(lcm, r);
            r = r / g;
            lcm = lcm / g;
            d_div = log10(lcm) + 1;

            for (int i = 0; i <= d_q; ++i) printf(" ");
            printf("%lld\n", r);
            printf("%lld ", q);
            for (int i = 0; i <d_div; ++i) printf("-");
            printf("\n");
            for (int i = 0; i <= d_q; ++i) printf(" ");
            printf("%lld\n", lcm);
        }
    }
    return 0;
}
