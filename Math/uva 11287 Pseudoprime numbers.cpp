#include <bits/stdc++.h>
using namespace std;

long long bigmod(long long a, long long b, long long M) {
    if (b == 0)
        return 1 % M;
    long long x = bigmod(a, b/2, M);
    x = (x * x) % M;
    if (b & 1) x = (x * a) % M;
    return x;
}

bool miillerTest(long long d, long long n) {
	long long a = 2 + rand() % (n - 4); // random a.

    long long x = bigmod(a, d, n);
	if (x == 1 || x == n-1) return true; // prime

	// iterate r times. r as 2^r
	while (d != n-1) {
		x = (x * x) % n;
		d *= 2;

		if (x == 1)	 return false;
		if (x == n-1) return true;
	}
	return false; 	// composite
}

bool isPrime(long long n, int k) {
	if (n == 2 || n == 3) return true;
	if (n < 2 || n%2 == 0) return false;

	// Find r such that n - 1 = 2^r * d for some r > 0
	long long d = n - 1;
	while (d % 2 == 0) d /= 2;

	// Iterate  k times.
	for (int i = 0; i < k; i++) if (miillerTest(d, n) == false) {
        return false;
	}
	return true;
}

int main() {
    //freopen("inp.txt", "r", stdin);

    long long p, a;
    while (scanf("%lld %lld", &p, &a))
    {
        if (p==0 && a==0) break;

        if (isPrime(p, 4)) puts("no");
        else if (bigmod(a, p, p) == a) puts("yes");
        else puts("no");
    }
    return 0;
}
