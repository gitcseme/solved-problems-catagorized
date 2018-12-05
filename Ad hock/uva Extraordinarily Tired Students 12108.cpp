#include <bits/stdc++.h>
using namespace std;

int ab[13][3], c[13];
int n;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}
int getLcm(int a, int b) {
    return (a*b / gcd(a, b));
}

bool check () {
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (c[i] <= ab[i][0]) ++cnt;
    if (cnt == n) return true;

    for (int i = 0; i < n; ++i) {
        if (c[i] == ab[i][0]+ab[i][1] || (c[i] == ab[i][0] && n <= 2*cnt)) c[i] = 1;
        else ++c[i];
    }
    return false;
}

int main() {
    freopen("zzz.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cse = 0;
    while (cin >> n && n) {

        int lcm = 1;
        for (int i = 0; i < n; ++i) {
            cin >> ab[i][0] >> ab[i][1] >> c[i];
            lcm = getLcm(lcm, ab[i][0] + ab[i][1]);
        }

        bool all_awake = false;;
        for (int i = 1; i <= lcm; ++i) {
            all_awake = check();
            if (all_awake) {
                cout << "Case " << ++cse << ": " << i << "\n";
                break;
            }
        }
        if (!all_awake) cout << "Case "<<++cse<<": -1\n";
    }

    return 0;
}
