#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b==0 ? a : gcd(b, a%b);
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    long long a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (gcd(a, b) != 1)
            cout << "-1\n";
        else
            cout << (a*b - a - b + 1) << "\n";
    }

    return 0;
}

/* Chicken McNugget Theorem
   The Theorem states that for any two relatively prime positive integers m, n
   the greatest integer that cannot be written in the form am + bn
   for nonnegative integers a, b  is m*n - m - n.

    All > (m*n-m-n) can be formed using the form am + bn.
*/
