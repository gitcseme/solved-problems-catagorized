#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 2];
vector<long long> primes;

void sieve() {
    int sqrtN = (int)sqrt((double)N) + 1;
    for (int i = 3; i <= sqrtN; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            for (int j = i*i; j <= N; j += 2*i)
                status[j>>6] = on(status[j>>6], ((j>>1) & 31));

    primes.push_back((long long)2 * 2);
    for (int i = 3; i <= N; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            primes.push_back((long long)i * i);
}

int main() {
    sieve();
    int T;
    long long n, k, choice, gf_hate;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &n, &k);
        choice = ( upper_bound(primes.begin(), primes.end(), n) - primes.begin() );
        if (k >= n){
            printf("%lld 0\n", choice);
            continue;
        }
        gf_hate = ( upper_bound(primes.begin(), primes.end(), k) - primes.begin() );
        printf("%lld %lld\n", choice, choice-gf_hate);
    }

    return 0;
}
