#include <cstdio>
#include <cstring>

#define mod 100000007
int coin[55];
int lim[55];
int mem[55][1005];
int dp(int i, int k);

int main() {
    int tc, n, k, cse = 0;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &n, &k);
        for (int j = 0; j < n; ++j) scanf("%d", &coin[j]);
        for (int j = 0; j < n; ++j) scanf("%d", &lim[j]);

        memset(mem, -1, sizeof(mem));
        int ways = dp(n-1, k);
        printf("Case %d: %d\n", ++cse, ways);
    }
    return 0;
}

int dp(int i, int k) {
    if (k == 0) return 1;
    if (k < 0 || i < 0)  return 0;

    if (mem[i][k] != -1) return mem[i][k];

    int res = 0;
    res += dp(i-1, k) % mod;
    for (int j = 1; j <= lim[i]; ++j) {
        if (k - coin[i] * j >= 0)
            res += dp(i-1, k - coin[i] * j) % mod;
        else break;
    }

    return mem[i][k] = res % mod;
}
