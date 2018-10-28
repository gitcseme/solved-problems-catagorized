#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

#define N 10001000
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

int main () {
    //FI;

    sieve();
    int cnt, amt = 664640; // number of primes within 10001000
    long long n, sq, ans;

    while (scanf("%lld", &n), n)
    {
        n = abs(n);
        sq = sqrt(n) + 1;
        cnt = 0; ans = 0;
        for (int i = 0; i < amt && P[i] <= sq; ++i) {
            if (n % P[i] == 0) {
                ++cnt;
                while (n % P[i] == 0) n = n / P[i];
                ans = P[i];
            }
        }
        if (n > 1 && ans != n) {
            ans = max(ans, n);
            ++cnt;
        }
        if (cnt > 1) printf("%lld\n", ans);
        else puts("-1");
    }

    return 0;
}
