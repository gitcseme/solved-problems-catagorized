#include <bits/stdc++.h>
using namespace std;

struct E {
    int w, q, ind;
    E () {};
    E (int _ind, int _w, int _q) {
        ind = _ind;
        w = _w;
        q = _q;
    }
    bool operator < (E x) {
        if (w != x.w) return w < x.w;
        return q > x.q;
    }
} a[1005];

int path[1005], dp[1005];

void print (int mxInd) {
    if (mxInd == -1) return;
    print(path[mxInd]);
    printf("%d\n", a[mxInd].ind);
}

int main () {
    freopen("inp.txt", "r", stdin);
    int w, q, n = 0;
    while (scanf("%d %d", &w, &q) == 2) a[n] = E(++n, w, q);
    sort(a, a+n);

    int ans = 0, mxInd;
    path[0] = -1; dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        dp[i] = 1; path[i] = -1;

        for (int j = 0; j < i; ++j) {
            if (a[i].w > a[j].w && a[i].q < a[j].q)
            {
                if (1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    path[i] = j;
                }
            }
        }

        if (dp[i] > ans) {
            ans = dp[i];
            mxInd = i;
        }
    }

    printf("%d\n", ans);
    print(mxInd);

    return 0;
}
