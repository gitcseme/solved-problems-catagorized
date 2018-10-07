#include <bits/stdc++.h>
#define pb          push_back
#define all(x)      x.begin(),x.end()
#define ms(a,v)     memset(a,v,sizeof a)
#define ff          first
#define ss          second
#define mp          make_pair
#define gc          getchar
#define pf          printf
#define sc          scanf
#define sz(a)       (int)a.size()
#define CIN         ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(NULL)
#define intlim      2147483648

#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int main() {
    FI;

    int n, caseno = 0;
    int cre[15], req[15];

    while (1) {
        sc("%d", &n);
        if (n < 0) break;
        for (int i = 0; i < 12; ++i) sc("%d", &cre[i]);
        for (int i = 0; i < 12; ++i) sc("%d", &req[i]);

        int available = n;
        pf("Case %d:\n", ++caseno);
        for (int i = 0; i < 12; ++i) {
            if (req[i] > available) {
                pf("No problem. :(\n");
            }
            else {
                available -= req[i];
                pf("No problem! :D\n");
            }
            available += cre[i];
        }
    }

    return 0;
}
