#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {printf("%d ", i);} printf("\n");
#define DEBUG(x) printf("*%d*\n", x);
using namespace std;

int main() {
    //FI;

    int n;
    scanf("%d", &n);
    vector<int> dp(3); // dp[i] - total point such that we did activity i considered last.

    for (int day = 0; day < n; ++day) {
        vector<int> new_dp(3, 0);
        vector<int> c(3);
        for (int i = 0; i < 3; ++i) {
            scanf("%d", &c[i]);
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i != j) {
                    new_dp[j] = max(new_dp[j], dp[i] + c[j]);
                }
            }
        }
        dp = new_dp;
    }

    printf("%d", max(max(dp[0], dp[1]), dp[2]));

    return 0;
}
