#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
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

bool emirp (int n) {
    if (n < 10) return false; // 2, 3, 5, 7
    string s = to_string(n);
    int nn;
    reverse(s.begin(), s.end());
    stringstream sso(s);
    sso >> nn;
    if (nn == n) return false; // palindromes are not emirp.
    return isPrime(nn);
}

int main() {
    //FI;

    sieve();
    int n;

    while (scanf("%d", &n) == 1)
    {
        if (isPrime(n)) {
            if (emirp(n))
                printf("%d is emirp.", n);
            else
                printf("%d is prime.", n);
        }
        else
            printf("%d is not prime.", n);
        puts("");
    }

    return 0;
}
