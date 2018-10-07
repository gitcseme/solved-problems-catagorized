#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int interceptions(vector<int>& missile, int len);

int main() { ios::sync_with_stdio(0); cin.tie(0);

    int m, tc = 0;
    while (1) {
        vector <int> missile;
        while (scanf("%d", &m)) {
            if (m == -1) break;
            missile.push_back(m);
        }
        int len = missile.size();
        if (len == 0) break;

        int max_interception = interceptions(missile, len);
        if (tc) printf("\n");
        printf("Test #%d:\n  maximum possible interceptions: %d\n", ++tc, max_interception);
    }

    return 0;
}

int interceptions(vector<int>& missile, int len) {
    int dp[len];
    for(int i = 0; i < len; ++i) dp[i] = 1;

    int mx = 1;
    for (int i = 1; i < len; ++i)
        for (int j = 0; j < i; ++j)
            if (missile[i] <= missile[j]) {
                dp[i] = max(1 + dp[j], dp[i]);
                mx = max(mx, dp[i]);
            }
    return mx;
}

