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
    int n, q, caseno = 0;

    while (sc("%d %d", &n, &q)) {
        if (n==0 && q==0)
            break;
        int a[n];
        for (int i = 0; i < n; ++i)
            sc("%d", &a[i]);
        sort(a, a+n);
        pf("CASE# %d:\n", ++caseno);
        while(q--) {
            int e;
            sc("%d", &e);
            int pos = lower_bound(a, a+n, e) - a;

            if (a[pos] != e) {
                pf("%d not found\n", e);
            }
            else {
                pf ("%d found at %d\n", e, pos+1);
            }
        }
    }

    return 0;
}
