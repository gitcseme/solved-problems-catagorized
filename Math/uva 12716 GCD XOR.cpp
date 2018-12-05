#include <bits/stdc++.h>
using namespace std;

#define MAXN 30000000
long long cum[(MAXN + 5)];

void preCal() {
    for (int g = 1; g <= MAXN; ++g) {
        for (int i = 2; i <= MAXN/g; ++i) {
            int a = i * g;
            int b = a - g;
            if ((a^b) == g) ++cum[a];
        }
    }
    for (int i = 3; i <= MAXN; ++i) cum[i] += cum[i-1];
}

int main () {
    preCal();
    int t, N;
    scanf("%d", &t);

    for (int caseno = 1; caseno <= t; ++caseno) {
        scanf("%d", &N);
        printf("Case %d: %lld\n", caseno, cum[N]);
    }

    return 0;
}
