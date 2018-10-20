#include <bits/stdc++.h>
using namespace std;

#define N 5300000
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 2];
vector<int> primes;
vector<long long> ans;

void sieve() {
    int sqrtN = (int)sqrt((double)N) + 1;
    for (int i = 3; i <= sqrtN; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            for (int j = i*i; j <= N; j += 2*i)
                status[j>>6] = on(status[j>>6], ((j>>1) & 31));

    primes.push_back(2);
    for (int i = 3; i <= N; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            primes.push_back(i);
}

void gen() {
    int cnt = 0, len = 365560;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (primes[i] * primes[j] > 10527451) break;
            ans.push_back((long long)primes[i] * primes[j]);
            ++cnt;
            if (cnt > 2000000) return;
        }
    }
}

int main() {
    sieve();
    gen();
    sort(ans.begin(), ans.end());
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", ans[n-1]);
    }

    return 0;
}
