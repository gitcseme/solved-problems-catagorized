#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

#define N 50000
vector<int> primes;
bool mark[N];

void Eratosthenes() {
    for(int i = 3; i * i <= N; i += 2)
        if (!mark[i])
            for (int j = i * i; j <= N; j += 2*i)
                mark[j] = true;

    primes.push_back(2);
    for (int i = 3; i <= N; i += 2)
        if (!mark[i])
            primes.push_back(i);
}

vector <int> fact;
void factorize (long long n) {
    int sq = sqrt(n) + 1;
    for (int i = 0; primes[i] <= sq; ++i) {
        int p = primes[i];
        if (n % p == 0) {
            while(n % p == 0) {
                n = n / p;
                fact.push_back(p);
            }
        }
    }
    if (n > 1) fact.push_back((int)n);
    sort(fact.begin(), fact.end());
}

int main () {
    //FI;
    Eratosthenes();

    long long n;
    while (scanf("%lld", &n), n)
    {
        fact.clear();
        printf("%lld =", n);
        if (n < 0) printf(" -1 x");

        factorize(abs(n));
        for (int i = 0, l = fact.size(); i < l; ++i) {
            printf(" %d", fact[i]);
            if (i != l-1) printf(" x");
        }
        puts("");
    }

    return 0;
}
