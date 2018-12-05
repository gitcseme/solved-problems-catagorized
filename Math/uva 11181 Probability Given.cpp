#include <bits/stdc++.h>
using namespace std;

int on (int mask, int pos) { return mask |= (1<<pos); }
bool isOn(int mask, int pos) { return (bool)(mask & (1<<pos)); }

int N, r;
double p[25], SampleSpace;
map <int, double> prob;

void solve (int mask, int i, int cnt) {

    if (cnt == r) {
        double local = 1.0;
        for (int j = 0; j < N; ++j) {
            if (isOn(mask, j)) local *= p[j];
            else local *= (1.0-p[j]);
        }
        SampleSpace += local;
        for (int j = 0; j < N; ++j) {
            if (isOn(mask, j))
                prob[j+1] = prob[j+1] + local;
        }
        return;
    }
    if (i == N) return;

    solve(mask, i+1, cnt);
    solve(on(mask, i), i+1, cnt+1);
}

int main () {
    int caseno = 0;
    while (scanf("%d %d", &N, &r) && (N || r))
    {
        for (int i = 0; i < N; ++i) scanf("%lf", &p[i]);

        prob.clear();
        SampleSpace = 0.0;
        solve(0, 0, 0);

        printf("Case %d:\n", ++caseno);
        for (int i = 0; i < N; ++i) {
            double ans = prob[i+1] / SampleSpace;
            printf("%.6f\n", ans);
        }
    }
    return 0;
}
