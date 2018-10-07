#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000000 + 5
int phi[MAXN];
unsigned long long cum[MAXN];

void preCall() {
    for (int i = 2; i < MAXN; ++i) {
        if(!phi[i]) {
            for (int j = i; j < MAXN; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = (phi[j]/i) * (i-1);
            }
        }
    }
    cum[1] = 0;
    for (int i = 2; i < MAXN; ++i)
        cum[i] = cum[i-1] + 1llu * phi[i] * phi[i];
}

int main() {
    preCall();
    int t, a, b, cse = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        printf("Case %d: %llu\n", ++cse, cum[b] - cum[a-1]);
    }

    return 0;
}
