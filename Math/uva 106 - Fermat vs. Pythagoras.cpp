#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000006;
bool nor[MAXN];

int main () {
    int limit;
    while (scanf("%d", &limit) == 1)
    {
        memset(nor, 0, sizeof(nor));
        int valid = 0, a, b, c = 0;

        int sq = sqrt(limit) + 1;
        for (int n = 1; n <= sq; ++n) {
            for (int m = n+1; m <= sq; ++m) {
                c = m*m + n*n;
                a = m*m - n*n;
                b = 2*m*n;
                if (c > limit) break;

                if (__gcd(a, b) == 1) {
                    ++valid;
                    for (int z = 1; z*c <= limit; ++z)
                        nor[a*z] = nor[b*z] = nor[c*z] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= limit; ++i) if (nor[i] == 0) ++cnt;
        printf("%d %d\n", valid, cnt);
    }

    return 0;
}
