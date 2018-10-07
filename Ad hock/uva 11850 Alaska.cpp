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
    int n;

    while(sc("%d", &n) && n) {
        int charge[n];
        for (int i = 0; i < n; ++i) {
            sc("%d", &charge[i]);
        }
        sort(charge, charge+n);
        bool poss = true;
        if ((2*(1422-charge[n-1]) > 200))
            poss = false;
        else {
            int pre = 0;
            for (int i = 0; i < n; ++i) {
                if (charge[i] - pre > 200) {
                    poss = false;
                    break;
                }
                pre = charge[i];
            }
        }
        if(poss) puts("POSSIBLE");
        else puts("IMPOSSIBLE");
    }

    return 0;
}
