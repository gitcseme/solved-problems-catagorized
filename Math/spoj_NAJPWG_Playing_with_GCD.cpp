#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000 + 5
int phi[MAXN];
int cum[MAXN];

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
    cum[1] = 0;
    for (int i = 1; i < MAXN; ++i)
        cum[i] = cum[i-1] + (i - phi[i]);
}

int main () {
    preCall();
    int t, n, cse = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("Case %d: %d\n", ++cse, cum[n]);
    }

    return 0;
}
