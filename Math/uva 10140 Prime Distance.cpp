#include <bits/stdc++.h>
using namespace std;

#define N 1000000
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 2];
int primes[700000];
int amt = 0;

void sieve() {
    int sqrtN = (int)sqrt((double)N) + 1;
    for (int i = 3; i <= sqrtN; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0) {
            for (int j = i*i; j <= N; j += 2*i)
                status[j>>6] = on(status[j>>6], ((j>>1) & 31));
        }

    primes[amt++] = 2;
    for (int i = 3; i <= 50000; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            primes[amt++] = i;
}

bool isPrime(int n) {
    if (n <= N) {
        if (n == 2) return true;
        if (n < 2 || !(n&1)) return false;
        return check(status[n>>6], ((n>>1) & 31)) == 0;
    }
    int sq = sqrt(n)+1;
    for (int i = 0; i < amt && (primes[i] <= sq); ++i) {
        if (n % primes[i] == 0) return false;
    }
    return true;
}

int main() {
    //freopen("inp.txt", "r", stdin);

    sieve();
    int L, U, p1, p2, p3, p4, pre;

    while (scanf("%d %d", &L, &U) != EOF)
    {
        int cnt = 0;
        for (long long i = L; i <= U; ++i)
        {
            if (isPrime(i)) {
                ++cnt;
                if (cnt == 1) {
                    p1 = i;
                }
                else if (cnt == 2) {
                    p3 = p1;
                    p4 = p2 = i;
                }
                else {
                    if (i-pre < p2-p1) {
                        p1 = pre; p2 = i;
                    }
                    if (i-pre > p4-p3){
                        p3 = pre; p4 = i;
                    }
                }
                pre = i;
            }
        }
        if (cnt < 2) printf("There are no adjacent primes.\n");
        else printf("%d,%d are closest, %d,%d are most distant.\n", p1,p2,p3,p4);
    }

    return 0;
}
