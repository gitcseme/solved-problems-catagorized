#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int valor (char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return ((c - 'A') + 10);
}

char a[] = {'A', 'B', 'C', 'D', 'E', 'F'};
char ret (int r) {
    if (r < 10) return (r+'0');
    else {
        r = r % 10;
        return a[r];
    }
}

string solve (int dec, int b) {
    string local;
    while (dec != 0) {
        int r = dec % b;
        local = local + ret(r);
        dec = dec / b;
    }
    reverse(local.begin(), local.end());
    return local;
}

int main() {
    //FI;

    string v, line;
    int b1, b2;

    while (getline(cin, line)) {
        stringstream sso(line);
        sso >> v >> b1 >> b2;
        bool zero = true;
        for (int i = 0; i < v.size(); ++i) if (v[i] != '0'){
            zero = false;
            break;
        }
        if (zero) {
            puts("      0");
            continue;
        }

        int decimal = 0, pw = 0;
        for (int i = v.size()-1; i >= 0; --i) {
            decimal = decimal + valor(v[i]) * round( pow(b1, pw) );
            ++pw;
        }

        string ans = solve(decimal, b2);
        if (ans.size() <= 7) printf("%7s\n", ans.c_str());
        else puts("  ERROR");
    }

    return 0;
}
