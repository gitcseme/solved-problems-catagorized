#include <bits/stdc++.h>
using namespace std;


int main () {
    //freopen("inp.txt", "r", stdin);

    int tc, M, x, y, carry;
    scanf("%d", &tc);

    for(int caseno = 0; caseno < tc; ++caseno) {
        scanf("%d", &M);
        int sum[M];
        carry = 0;
        for (int i = 0; i < M; ++i) {
            scanf("%d %d", &x, &y);
            sum[i] = x+y;
        }
        for (int i = M-1; i >= 0; --i) {
            x = sum[i];
            sum[i] = (sum[i] + carry) % 10;
            carry = (x + carry) / 10;
        }

        for (int i = 0; i < M; ++i) printf("%d", sum[i]);
        printf("\n");

        if (caseno != tc-1) puts("");
    }
    return 0;
}
