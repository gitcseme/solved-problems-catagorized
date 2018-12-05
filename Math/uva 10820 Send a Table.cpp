#include <bits/stdc++.h>
using namespace std;

int phi[50002];
long long cum[50002];

void preCal() {
    phi[1] = 1;
    for (int i = 2; i <= 50001; ++i) {
        if(!phi[i]) {
            for (int j = i; j <= 50001; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = (phi[j] / i) * (i-1);
            }
        }
    }
    cum[1] = 1;
    for (int i = 2; i < 50001; ++i) cum[i] = cum[i-1] + phi[i];
}

int main() {
    preCal();
    int N;
    while (scanf("%d", &N) && N) {
        printf("%lld\n", (cum[N] * 2) - 1);
    }

    return 0;
}
