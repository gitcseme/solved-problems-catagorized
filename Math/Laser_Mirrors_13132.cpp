#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000 + 5
int phi[MAXN];

void preCal() {
    for (int i = 1; i < MAXN; ++i) phi[i] = i;
    for (int i = 2; i < MAXN; ++i)
        if(phi[i] == i)
            for (int j = i; j < MAXN; j += i)
                phi[j] -= phi[j] / i;
}

int main() {
    preCal();
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("%d\n", phi[N]);
    }

    return 0;
}
