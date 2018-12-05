#include <bits/stdc++.h>
using namespace std;

int f[5000];
vector<int> cycle[1005];

void preCal() {
    f[0] = 0, f[1] = 1;
    cycle[1].push_back(0);

    for (int mod = 2; mod <= 1000; ++mod) {
        cycle[mod].push_back(0), cycle[mod].push_back(1);

        for (int i = 2; i < 5000; ++i) {
            f[i] = ( f[i-1]%mod + f[i-2]%mod ) % mod;
            if (f[i] == 0 && f[i-1] == 1) break;
            cycle[mod].push_back(f[i]);
        }
    }
}

int bigmod(unsigned long long a, unsigned long long b, int M) {
    if (b == 0)
        return 1 % M;
    int x = bigmod(a, b/2, M);
    x = (x * x) % M;
    if (b & 1) x = (x * a) % M;
    return x;
}

int main () {
    freopen("inp.txt", "r", stdin);
    preCal();

    int t, n;
    unsigned long long a, b;
    scanf("%d", &t);

    while (t--) {
        scanf("%llu %llu %d", &a, &b, &n);
        int M = cycle[n].size();
        int ind = bigmod(a%M, b, M);
        printf("%d\n", cycle[n][ind]);
    }

    return 0;
}
