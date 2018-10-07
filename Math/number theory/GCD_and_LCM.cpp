#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b==0 ? a : gcd(b, a%b);
}

int main() {

    int T, a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        int g = gcd(a, b);

        cout << g << " " << ((long long)a*b)/g << "\n";
    }

    return 0;
}
