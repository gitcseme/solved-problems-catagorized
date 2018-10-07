#include <bits/stdc++.h>
using namespace std;
int arr[200005];
long long aux[200005];
int phi(int n) {
    int ret = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            ret -= ret / p;
        }
    }
    if (n > 1) ret -= ret / n;
    return ret;
}

int gcd(int a, int b) {
    return b==0 ? a : gcd(b, a%b);
}

int getNumarator(int d, long long k) {
    int e = (int)(k - aux[d-1]);
    int cnt = 0, i;
    for(i = 0; i <= d; ++i) {
        if (gcd(i, d) == 1) ++cnt;
        if (cnt == e) break;
    }
    return i;
}

int main() {
    arr[1] = 2;
    aux[0] = 0; aux[1] = 2;
    for (int i = 2; i <= 200000; ++i) {
        arr[i] = phi(i);
        aux[i] = (aux[i-1] + arr[i]);
    }
    long long k;
    while(scanf("%lld", &k) && k) {
        int d = lower_bound(aux, aux+200000, k) - aux;
        int n = getNumarator(d, k);
        printf("%d/%d\n", n, d);
    }

    return 0;
}
