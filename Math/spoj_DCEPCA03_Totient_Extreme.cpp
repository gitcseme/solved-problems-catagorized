#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000 + 2
int phi[MAXN];
unsigned long long cum[MAXN];

void preCall() {
    phi[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if(!phi[i]) {
            for (int j = i; j < MAXN; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = (phi[j]/i) * (i-1);
            }
        }
    }
    unsigned long long H = 0;
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j <= i; ++j) {
            H = H + 1llu * phi[i] * phi[j];
            if (i != j)
                H = H + 1llu * phi[i] * phi[j];
        }
        cum[i] = H;
    }
}

int main() {
    preCall();
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%llu\n", cum[n]);
    }

    return 0;
}
