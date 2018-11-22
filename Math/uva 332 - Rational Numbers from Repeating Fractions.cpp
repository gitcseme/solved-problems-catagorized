#include <bits/stdc++.h>
#define forn(a, n) for (int i = a; i <= n; ++i)
using namespace std;

long long gcd (long long a, long long b) {
    return b == 0 ? a : gcd(b, a%b);
}
long long X10[10];

int main(){
    int j, caseno = 1;
    X10[0] = 1;
    string s;
    forn(1, 9) X10[i] = X10[i-1] * 10;

    while (cin >> j && j != -1) {
        cin >> s;
        int len = s.size();
        long long x = 0, a, b;
        forn(2, len-1) x = x*10 + s[i]-'0';

        if (j) {
            a = x - x/X10[j];
            b = X10[len-2] - X10[len-2-j]; //k = len-2-j
        }
        else {
            a = x;
            b = X10[len-2];
        }
        long long g = gcd(a, b);
        printf("Case %d: %lld/%lld\n", caseno++, a/g, b/g);
    }

    return 0;
}
