#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("inp.txt", "r", stdin);
    double ans;
    int p, q, r, s, lenu, lend;

    while (scanf("%d %d %d %d", &p, &q, &r, &s) != EOF) {
        ans = 1.0;
        vector <int> up, down;
        for (int i = p-q+1; i <= p; ++i) up.push_back(i);
        for (int i = 1; i <= s; ++i) up.push_back(i);
        for (int i = r-s+1; i <= r; ++i) down.push_back(i);
        for (int i = 1; i <= q; ++i) down.push_back(i);

        lenu = up.size();
        lend = down.size();
        int i = 0, j = 0;
        for ( ; i < lenu; ++i) {
            ans *= up[i];
            for ( ; j < lend; ++j) {
                if (ans < 1) break;
                ans /= down[j];
            }
        }
        while (i < lenu) ans *= up[i++];
        while (j < lend) ans /= down[j++];

        printf("%.5f\n", ans);
    }

    return 0;
}
