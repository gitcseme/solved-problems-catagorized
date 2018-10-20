#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

#define PI 3.141592654

int main() {
    //FI;
    int tc;
    double d, v, u, sD_time, s_time, thet, ans;
    cin >> tc;

    for (int caseno = 1; caseno <= tc; ++caseno) {
        cin >> d >> v >> u;

        if (v >= u || v==0 || u==0) {
            printf("Case %d: can't determine\n", caseno);
            continue;
        }

        s_time = d / u;
        thet = asin(v/u);
        sD_time = d / (u * (cos(thet)));

        ans = abs(sD_time - s_time);
        printf("Case %d: %.3f\n", caseno, ans);
    }

    return 0;
}
