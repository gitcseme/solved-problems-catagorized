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

#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

const int mx = 4010;
vector <long long> v;
long long a[mx][4];


int main () {
    FI;

    int tc;
    sc("%d", &tc);
    while (tc--) {
        int n;
        sc("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld %lld %lld %lld", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
        }

        long long ans = 0, local;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                v.push_back(a[i][0] + a[j][1]);
            }
        }
        sort(all(v));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                local = -(a[i][2] + a[j][3]);
                ans += (upper_bound(all(v), local) - lower_bound(all(v), local));
            }
        }
        pf("%lld\n", ans);
        if(tc) puts("");
        v.clear();
    }

    return 0;
}
