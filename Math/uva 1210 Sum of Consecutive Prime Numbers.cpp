#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

#define N 10004
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
bool isPrime(int n) {
    if (n == 2) return true;
    if (n < 2 || !(n&1)) return false;
    return check(status[n>>6], ((n>>1) & 31)) == 0;
}

int main() {
    //FI;
    sieve();

    int n;
    while (scanf("%d", &n)==1 && n)
    {
        int repCount = 0, curSum = 0, curPrime = 0, x = 0;
        if (isPrime(n)) ++repCount;

        for (int i = 0; primes[curPrime] <= (n/2); ++i) {
            curSum += primes[x++];

            while (curSum > n) {
                curSum = curSum - primes[curPrime];
                ++curPrime;
            }

            if (curSum == n) {
                ++repCount;
                curSum = curSum - primes[curPrime];
                ++curPrime;
            }
        }

        printf("%d\n", repCount);
    }

    return 0;
}
