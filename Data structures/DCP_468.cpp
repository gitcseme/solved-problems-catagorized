#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int main() {
    //FI;

    int tc, N, M, Q, x, y, l, r;
    scanf("%d", &tc);

    for (int caseno = 1; caseno <= tc; ++caseno) {
        scanf("%d %d %d", &N, &M, &Q);
        int len = (int)sqrt(N) + 1;
        unsigned long long a[N], b[len], c[M];

        for (int i = 0; i < N; ++i) scanf("%llu", &a[i]);

        scanf("%llu", &c[0]);
        for (int i = 1; i < M; ++i) {
            scanf("%llu", &c[i]);
            c[i] = c[i-1] + c[i];
        }

        memset(b, 0, sizeof(b));

        while (Q--) {
            scanf("%d %d %d %d", &x, &y, &l, &r);
            --x, --y, --l, --r;
            long long value = (x==0 ? c[y] : c[y] - c[x-1]);
            int c_l = l / len, c_r = r / len;

            if (c_l == c_r)
            {
                for (int i = l; i <= r; ++i)
                    a[i] += value;
            }
            else
            { // k-th block starts at (length * k) and ends at (length *(k+1) - 1)
              // Left partial block
                for (int i = l, block_end = len * (c_l + 1) - 1; i <= block_end; ++i)
                    a[i] += value;

                // Middle complete block
                for (int i = c_l + 1; i <= c_r - 1; ++i)
                    b[i] += value;

                // Right partial block
                for (int i = (len * c_r); i <= r; ++i)
                    a[i] += value;
            }
        }

        printf("Case %d:\n", caseno);
        int i;
        for (i = 0; i < N-1; ++i)
            printf("%llu ", (a[i] + b[i / len]));
        printf("%llu\n", (a[i] + b[i / len]));
    }

    return 0;
}
