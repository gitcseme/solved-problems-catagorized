#include <bits/stdc++.h>
using namespace std;

char a[105], b[105];
int M, N, dp[105][105];
string ans[105][105];

string solution() {
    for (int i = 0; i <= M; ++i) dp[i][0] = 0, ans[i][0] = "";
    for (int j = 0; j <= N; ++j) dp[0][j] = 0, ans[0][j] = "";

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j)
        {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans[i][j] = ans[i-1][j-1] + a[i-1];
            }
            else if (dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                ans[i][j] = ans[i-1][j];
            }
            else if (dp[i][j-1] > dp[i-1][j]) {
                dp[i][j] = dp[i][j-1];
                ans[i][j] = ans[i][j-1];
            }
            else {
                dp[i][j] = dp[i-1][j];
                ans[i][j] = min(ans[i-1][j], ans[i][j-1]);
            }
        }
    }

    if (dp[M][N] == 0) return ":(";
    return ans[M][N];
}

int main () {
    freopen("inp.txt", "r", stdin);

    int t;
    scanf("%d", &t);
    for (int cse = 1; cse <= t; ++cse) {
        getchar();
        scanf("%s %s", a, b);
        M = strlen(a);
        N = strlen(b);
        printf("Case %d: %s\n", cse, solution().c_str());
    }

    return 0;
}
