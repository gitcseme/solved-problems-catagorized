#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

int main () {

    int n, a;
    while (scanf("%d", &a), a)
    {
        int g = abs(a);
        scanf("%d", &n);
        g = abs(n - g);
        while (scanf("%d", &n), n)
            g = __gcd(g, abs(n-a));

        printf("%d\n", g);
    }

    return 0;
}
