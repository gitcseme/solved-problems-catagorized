#include <bits/stdc++.h>
using namespace std;

/*As ans have to  correct upto 10^-6 fraction value, we can't say mid+1 OR mid-1 for high and low value
because fraction value can be between 0.0 to 0.99(That means between 1).That's why we cant increase or decrease directy 1 from mid value
of high and low.*/

double AB, AC, BC, R, S, s, hi, lo, AD, AE, DE, ADE, ABC, BDEC;
void getAns() {
    lo = 0, hi = AB;
    int cnt = 0;
    double r = 0;

    while (cnt < 100) {
        AD = (lo + hi) / 2;
        AE = (AD * AC) / AB;
        DE = (AD * BC) / AB;

        s = (AD + AE + DE) / 2;
        ADE = sqrt(s * (s-AD) * (s-AE) * (s-DE));

        S = (AB + AC + BC) / 2;
        ABC = sqrt(S * (S-AB) * (S-AC) * (S-BC));
        BDEC = ABC - ADE;

        r = ADE / BDEC;
        if (r < R) lo = AD;
        else hi = AD;
        ++cnt;
    }
}

int main () {
    freopen("inp.txt", "r", stdin);

    int T;
    scanf("%d", &T);
    for (int caseno = 1; caseno <= T; ++caseno) {
        scanf("%lf %lf %lf %lf", &AB, &AC, &BC, &R);

        getAns();
        printf("Case %d: %.10f\n",caseno, AD);
    }

    return 0;
}
