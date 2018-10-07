#include <bits/stdc++.h>
using namespace std;

#define N 2000000
int pf[N+1];

struct Num {
    int n, pft;
    Num(int nn, int pp) {
        n = nn; pft = pp;
    }
};
vector<Num> ANS;

void sieve() {
    int x;
    for(int i = 2; i <= N; i += 2) {
        if (!pf[i]) {
            pf[i] = 1;
            for (int j = i+i; j <= N; j += i) {
                x = j;
                while (x % i == 0) {
                    x = x / i;
                    ++pf[j];
                }
            }
        }
        if(i == 2) --i;
    }
}

bool comp(Num n1, Num n2) {
    if (n1.pft != n2.pft) return n1.pft < n2.pft;
    return n1.n < n2.n;
}

int main() {
    sieve();
    for (int i = 1; i <= N; ++i) {
        ANS.push_back(Num(i, pf[i]));
    }
    sort(ANS.begin(), ANS.end(), comp);
    int c = 0, x;
    while (1) {
        scanf("%d", &x); if (x == 0) break;
        printf("Case %d: %d\n", ++c, ANS[x-1].n);
    }
    return 0;
}
