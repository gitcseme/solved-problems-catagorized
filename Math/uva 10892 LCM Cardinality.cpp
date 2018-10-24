#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

#define N 50004
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 2];
vector<int> primes;

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

long long factorize (long long n) {
    long long ans = 1, sq = sqrt(n) + 1;

    for (int i = 0; primes[i] <= sq; ++i) {
        if (n % primes[i] == 0) {
            int e = 0;
            while (n % primes[i] == 0) {
                n = n / primes[i];
                ++e;
            }
            ans = ans * (2*e + 1);
        }
    }
    if (n > 1) ans = ans * (2*1 + 1);
    ans = (ans / 2) + 1;
    return ans;
}

int main () {
    //FI;

    sieve();
    long long n;
    while (scanf("%lld", &n), n)
        printf("%lld %lld\n", n, factorize(n));

    return 0;
}
