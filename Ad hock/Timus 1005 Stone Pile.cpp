#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

int num[25], ans = 1<<28, totalSum, n;

/* O(2^n) complexity */
void backtrack (int pos, int group1sum) {
    if (pos == n) {
        int group2sum = totalSum - group1sum;
        ans = min (ans, abs(group1sum - group2sum));
        return;
    }
    backtrack(pos + 1, group1sum); // leave it.
    backtrack(pos + 1, group1sum + num[pos]); // take it.
}

int main () {
    FI;
    scanf("%d", &n);
    totalSum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        totalSum += num[i];
    }

    backtrack(0, 0);
    cout << ans << "\n";

    return 0;
}
