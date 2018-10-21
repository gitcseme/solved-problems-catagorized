#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

long long f(int i) {
    if (i == 1) return 3;
    long long a = 0, x = i;

    while (x != 1) {
        if (x % 2 == 0) {
            x = x >> 1;
            ++a;
        }
        if ((x != 1) && (x%2 == 1)){
            x = 3*x + 1;
            x = x >> 1;
            a += 2;
        }
    }
    return a;
}

int main() {
    //FI;
    int L, R;

    while (scanf("%d %d", &L, &R))
    {
        if (L==0 && R==0) break;
        if (L > R) swap(L, R);

        long long ans = 0, local, S = 0;
        for(int i = L; i <= R; ++i) {
            local = f(i);
            if (local > S) {
                ans = i;
                S = local;
            }
        }
        printf("Between %d and %d, %lld generates the longest sequence of %lld values.\n", L, R, ans, S);
    }

    return 0;
}
