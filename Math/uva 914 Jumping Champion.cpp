#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

#define N 1000060
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 2];
vector<int> P;

void sieve() {
    int sqrtN = (int)sqrt((double)N) + 1;
    for (int i = 3; i <= sqrtN; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            for (int j = i*i; j <= N; j += 2*i)
                status[j>>6] = on(status[j>>6], ((j>>1) & 31));

    P.push_back(2);
    for (int i = 3; i <= N; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            P.push_back(i);
}

map <int, int> m;

int main () {
    //FI;
    sieve();

    int tc, L, U;
    scanf("%d", &tc);
    while (tc--)
    {
        m.clear();
        scanf("%d %d", &L, &U);
        int ll = lower_bound(P.begin(), P.end(), L) - P.begin();
        int uu = upper_bound(P.begin(), P.end(), U) - P.begin();

        int pre = P[ll];
        for (int cur = ll + 1; cur < uu; ++cur) {
            m[P[cur]-pre]++;
            pre = P[cur];
        }

        int mxC = 0, mx, mxF = 1;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second >= mxC) {
                if (it->second == mxC) mxF = 2;
                else mxF = 1;
                mxC = it->second;
                mx = it->first;
            }
        }
        if (mxF == 2 || mxC == 0) puts("No jumping champion");
        else printf("The jumping champion is %d\n", mx);
    }

    return 0;
}
