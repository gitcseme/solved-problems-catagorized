#include <bits/stdc++.h>
using namespace std;

#define N 1000006
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 2];

void sieve() {
    int sqrtN = (int)sqrt((double)N) + 1;
    for (int i = 3; i <= sqrtN; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            for (int j = i*i; j <= N; j += 2*i)
                status[j>>6] = on(status[j>>6], ((j>>1) & 31));
}
bool isPrime(int n) {
    if (n == 2) return true;
    if (n < 2 || !(n&1)) return false;
    return check(status[n>>6], ((n>>1) & 31)) == 0;
}

int main () {
    sieve();
    int n;

    while (scanf("%d", &n), n)
    {
        int b = 2, e = n-2;
        bool flag = true;
        while (b <= e) {
            if (isPrime(b) && isPrime(e)) {
                flag = false;
                printf("%d = %d + %d\n", n, b, e);
                break;
            }
            ++b, --e;
        }
        if (flag) printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}
