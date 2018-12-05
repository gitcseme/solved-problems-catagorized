#include <bits/stdc++.h>
using namespace std;

#define N 50000
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 5];
vector<int> primes;

struct fac {
    int base, pow;
    fac(int _base, int _pow) {
        base = _base;
        pow = _pow;
    }
};

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

vector <fac> factors;
int hipow;
void factorize(long long Num) {
    int cnt;
    for (int i = 0; (long long)primes[i]*primes[i] <= Num; ++i) {
        cnt = 0;
        if (Num % primes[i] == 0) {
            while (Num % primes[i] == 0) {
                ++cnt;
                Num /= primes[i];
            }
            factors.push_back(fac(primes[i], cnt));
        }
    }
    if (Num > 1) factors.push_back(fac(Num, 1));
}

int main () {
    freopen("inp.txt", "r", stdin);
    sieve();

    long long Num, ans;
    int cse = 0;
    while(scanf("%lld", &Num) && Num) {
        factors.clear();
        factorize(Num);
        printf("Case %d: ", ++cse);
        if (Num == 1) printf("2\n");
        else if (factors.size() == 1) printf("%lld\n", Num+1);
        else {
            ans = 0;
            for(int i = 0; i < factors.size(); ++i)
                ans += round ( pow(factors[i].base, factors[i].pow) );
            printf("%lld\n", ans);
        }
    }

    return 0;
}
