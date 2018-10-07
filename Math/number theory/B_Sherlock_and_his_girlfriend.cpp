#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 2];
void sieve(int n) {
    int sqrtN = (int)sqrt((double)n) + 1;
    for (int i = 3; i <= sqrtN; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            for (int j = i*i; j <= n; j += 2*i)
                status[j>>6] = on(status[j>>6], ((j>>1) & 31));
}
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(n&1)) return false;
    return check(status[n>>6], ((n>>1) & 31)) == 0;
}
int main() {
    int n;
    scanf("%d", &n);
    sieve(n+2);
    puts(n < 3 ? "1" : "2");
    ++n;
    for (int i = 2; i <= n; ++i)
        if (isPrime(i)) printf("1 ");
        else printf("2 ");

    return 0;
}
