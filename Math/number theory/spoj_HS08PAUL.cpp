#include <bits/stdc++.h>
using namespace std;

#define N 10000000
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 2];
int mark[N];

void sieve() {
    int sqrtN = (int)sqrt((double)N) + 1;
    for (int i = 3; i <= sqrtN; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            for (int j = i*i; j <= N; j += 2*i)
                status[j>>6] = on(status[j>>6], ((j>>1) & 31));
}

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(n&1)) return false;
    return check(status[n>>6], ((n>>1) & 31)) == 0;
}

void gen() {
    int x, y, n;
    for (int i = 0; (x=i*i) < N; ++i) {
        for (int j = 0; (y=j*j*j*j) < N; ++j) {
            n = x + y;
            if (n < N && isPrime(n))
                mark[n] = 1;
        }
    }
    for (int i = 1; i < N; ++i) mark[i] += mark[i-1];
}

int main() {
    sieve();
    gen();
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", mark[n]);
    }

    return 0;
}
