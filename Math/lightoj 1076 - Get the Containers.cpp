#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1003, mxCap = 1000000000;
int vessel[MAXN], m, n;

bool valid (long long cap) {

    long long tmp = 0;
    int cnt = 1;

    for (int i = 0; i < n; ++i) {
        if (tmp + vessel[i] <= cap) {
            tmp += vessel[i];
        }
        else { // new vessel needed.
            tmp = vessel[i];
            ++cnt;
        }
    }
    if (cnt > m) return false;
    else return true;
}

long long getAns (int maxi) {
    long long lo = maxi, hi = mxCap, ans, mid;

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (valid(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return ans;
}

int main () {
    freopen("inp.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    for (int caseno = 1; caseno <= T; ++caseno) {
        scanf("%d %d", &n, &m);
        int maxi = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &vessel[i]);
            if (vessel[i] > maxi) maxi = vessel[i];
        }
        long long ans = getAns(maxi);
        printf("Case %d: %lld\n", caseno, ans);
    }

    return 0;
}
