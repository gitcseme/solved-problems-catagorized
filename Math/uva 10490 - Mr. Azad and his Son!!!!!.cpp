#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    int sq = sqrt(n);
    for (long long i = 2; i <= sq; ++i)
        if (n%i == 0) return false;
    return true;
}

int main () {
    long long n;
    while (scanf("%lld", &n), n)
    {
        bool prime = isPrime(n);
        bool perfect = isPrime((1LL << n)-1);

        if (prime && perfect)
            printf("Perfect: %lld!\n", ((1LL << (n-1))* ((1LL << n)-1)) );
        else if (prime && !perfect)
            printf("Given number is prime. But, NO perfect number is available.\n");
        else if (!prime && !perfect)
            printf("Given number is NOT prime! NO perfect number is available.\n");
    }

    return 0;
}
