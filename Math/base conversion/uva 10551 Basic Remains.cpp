#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

string covertTob (long long ans, int b) {
    string ret = "";
    while(ans != 0) {
        int r = ans % b;
        ret = ret + (char)(r + '0');
        ans = ans / b;
    }
    return ret;
}

int main() {
    //FI;

    int b;
    char p[1005], m[15];
    while (scanf("%d", &b) && b)
    {
        scanf("%s %s", p, m);
        int lenp = strlen(p), lenm = strlen(m);

        long long mod = 0;
        for (int i = 0; i < lenm; ++i) mod = mod * b + (m[i] - '0');

        long long ans = 0;
        for (int i = 0; i < lenp; ++i) ans = (ans * b + (p[i] - '0')) % mod;

        if (ans == 0)
            putchar('0');
        else {
            string s = covertTob(ans, b);
            for (int i = s.size()-1; i >= 0; --i) putchar(s[i]);
        }
        puts("");
    }
    return 0;
}
