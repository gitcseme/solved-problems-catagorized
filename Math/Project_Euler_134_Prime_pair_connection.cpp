#include <bits/stdc++.h>
typedef unsigned long long ULL;
using namespace std;

#define N 32000
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 2];
vector<long long> primes, seg_primes;
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
bool mark[1000000 + 100];
void segment_sieve(ULL L, ULL R) {
    for (ULL p : primes) {
        if (p * p > R) break;
        ULL base = (L/p) * p;
        if (base < L) base += p;

        for (ULL j = base; j <= R; j += p)
            mark[j - L] = true;
        if (base == p) mark[base - L] = false;
    }
    if (L == 1) mark[0] = true;
}

ULL next_prime(ULL p) {
    bool f;
    ULL i;
    for (i = p + 2; i < 2 * p; i += 2) {
        f = true;
        for (ULL j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                f = false;
                break;
            }
        }
        if(f) break;;
    }
    return i;
}

long long egcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long d = egcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;

    return d;
}

long long linear_congruence(long long a, long long b, long long M) {
    long long x, y;
    long long d = egcd(a, M, x, y);
    long long sol_x = x * (b/d);
    sol_x = (sol_x%M + M) % M;
    return sol_x;
}

int main() {
    sieve();
    ULL S, L, R, len, T, p1, p2, c, a, M, x;
    long long b; // ULL can't take -ve value.
    cin >> T;
    while (T--) {
        cin >> L >> R;
        memset(mark, false, sizeof(mark));
        seg_primes.clear();
        segment_sieve(L, R);
        for (int i = 0; i <= (R-L); ++i) if(!mark[i]) seg_primes.push_back(L+i);

        len = seg_primes.size();
        seg_primes.push_back(next_prime((ULL)seg_primes[len-1]));

        S = 0;
        for (int i = 0; i < len; ++i) {
            p1 = seg_primes[i]; p2 = seg_primes[i+1]; c = log10(p1) + 1;
            a = round( pow(10, c) );
            b = -p1;
            M = p2;
            x = linear_congruence(a, b, M);
            S += (x * a + seg_primes[i]);
        }
        cout << S << "\n";
    }
    return 0;
}
