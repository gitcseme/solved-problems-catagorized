#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int main () {
    FI;
    int R, N, caseno = 0, ans;

    while (scanf("%d %d", &R, &N) == 2 && (R && N))
    {
        printf("Case %d: ", ++caseno);
        if (N * 26 + N < R) {
            printf("impossible\n");
        }
        else if (R <= N) {
            printf("0\n");
        }
        else {
            ans = (int)ceil(1.0*(R - N) / N);
            printf("%d\n", ans);
        }
    }

    return 0;
}
