#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

const int INF = 1e9 + 5;

int main() {
    //FI;

    int n;
    scanf("%d", &n);
    vector<int> h(n);
    for (int& x : h) scanf("%d", &x);

    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j : {i + 1, i + 2})
            dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
    }
    printf("%d\n", dp[n-1]);

    return 0;
}
