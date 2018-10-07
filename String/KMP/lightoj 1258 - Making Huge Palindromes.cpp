#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000006;

string text, pattern;
int suf[MAXN], n;

void lps () {
    int len = n, k = 0;
    for (int i = 1; i < len; ++i) {
        while (k > 0 && pattern[k] != pattern[i])
            k = suf[k - 1];
        if (pattern[k] == pattern[i])
            ++k;
        suf[i] = k;
    }
}

int KMP () {
    int len = n, k = 0, pat = n, common = 0;
    for (int i = 0; i < len; ++i) {
        while (k > 0 && pattern[k] != text[i])
            k = suf[k - 1];
        if (pattern[k] == text[i])
            ++k;
        if (i == n-1) {
            common = k;
        }
    }
    return common;
}

int main() {
    freopen("inp.txt", "r", stdin);

    int t;
    cin >> t;
    for (int caseno = 1; caseno <= t; ++caseno) {
        cin >> text;
        n = text.size();
        pattern = text;
        reverse(pattern.begin(), pattern.end());

        lps();
        int common = KMP();
        cout << "Case " << caseno << ": " <<(n+n - common) << "\n";
    }

    return 0;
}
