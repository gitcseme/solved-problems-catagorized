#include <bits/stdc++.h>
using namespace std;

const int mod = 10056;
int MAXN = 1000;
int ncr[1002][1002];

void get_nCr() {
    ncr[0][0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        for (int j = 0; j <= MAXN; ++j) {
            if (j > i) ncr[i][j] = 0;
            else if (j == i || j == 0) ncr[i][j] = 1;
            else ncr[i][j] = ( ncr[i-1][j] % mod + ncr[i-1][j-1] % mod ) % mod;
        }
    }
}

int dp[1002];
void preCal () {
    dp[0] = 1;
    for (int n = 1; n <= MAXN; ++n) {
        for (int r = 1; r <= n; ++r) {
            dp[n] = ( dp[n] + (ncr[n][r] * dp[n-r]) % mod ) % mod;
        }
    }
}

int main() {
    get_nCr();
    memset(dp, 0, sizeof(dp));
    preCal();
    int t, n;
    scanf("%d", &t);
    for (int caseno = 1; caseno <= t; ++caseno) {
        scanf("%d", &n);
        printf("Case %d: %d\n", caseno, dp[n]);
    }

    return 0;
}
