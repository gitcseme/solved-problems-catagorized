#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

#define N 100000002
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

bool isPrime(int n) {
    if (n == 2) return true;
    if (n < 2 || !(n&1)) return false;
    return check(status[n>>6], ((n>>1) & 31)) == 0;
}

int x;
bool meet(int n) {
    if (n%2 == 1) {
        x = 2;
        if (isPrime(n-2)) return true;
        return false;
    }
    int i = (int)(upper_bound(P.begin(), P.end(), n/2) - P.begin());
    for ( ; i >= 0; --i) {
        if (isPrime(n-P[i])) {
            if (P[i] == n-P[i]) continue;
            x = min(P[i], n-P[i]);
            return true;
        }
    }
    return false;
}

int main () {
    sieve();
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (meet(n)) printf("%d is the sum of %d and %d.\n", n, x, n-x);
        else printf("%d is not the sum of two primes!\n", n);
    }

    return 0;
}
