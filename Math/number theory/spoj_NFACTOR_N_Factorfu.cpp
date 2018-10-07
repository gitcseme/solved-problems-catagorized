#include <bits/stdc++.h>
using namespace std;

#define N 1000006
int factor[N], ANS[N][11];

void sieve() {
    factor[1] = 0;
    for(int i = 2; i <= N; i += 2) {
        if (factor[i] == 0) {
            for (int j = i; j <= N; j += i) ++factor[j];
        }
        if (i==2) --i;
    }
    for (int i = 1; i < N; ++i)
        for (int n = 0; n <= 10; ++n)
            ANS[i][n] = ANS[i-1][n] + (bool)(factor[i] == n);
}

int main() {
    sieve();

    int a, b, n, T, cnt;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &n);
        printf("%d\n", ANS[b][n] - ANS[a-1][n]);
    }

    return 0;
}
