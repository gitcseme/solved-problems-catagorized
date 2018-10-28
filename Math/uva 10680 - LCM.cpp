#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

#define N 1000006
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
    swap(P[1], P[2]);  // 3 and 5
}

int main () {
    //FI;
    sieve();
    int amt = P.size(), c2, c5;
    long long n;

    while (scanf("%lld", &n), n)
    {
        int lcm = 1;
        c2 = c5 = 0;
        for (int i = 2; i <= n; i *= 2) ++c2;
        for (int i = 5; i <= n; i *= 5) ++c5;
        for (int i = 0; i < c2 - c5; ++i) lcm = (lcm * 2) % 10;
        for (int i = 2; i < amt && P[i] <= n; ++i) {
            long long pp = P[i];
            while (pp * P[i] <= n) pp = pp * P[i];
            lcm = (lcm * pp) % 10;
        }
        printf("%d\n", lcm);
    }

    return 0;
}
