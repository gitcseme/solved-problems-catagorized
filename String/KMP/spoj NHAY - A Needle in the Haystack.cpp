#include <bits/stdc++.h>
using namespace std;

string pattern, text;
int suf[1000009];
int n;

void lps () {
    int len = n, k = 0; suf[0] = 0;
    for (int i = 1; i < len; ++i) {
        while (k > 0 && pattern[k] != pattern[i])
            k = suf[k - 1];
        if (pattern[k] == pattern[i])
            ++k;
        suf[i] = k;
    }
}

void KMP () {
    int len = text.size(), k = 0, pat = n;
    for (int i = 0; i < len; ++i) {
        while (k > 0 && pattern[k] != text[i])
            k = suf[k - 1];
        if (pattern[k] == text[i])
            ++k;
        if (k == pat) {
            k = suf[k - 1]; // advance option [simple is k = 0]
            printf("%d\n", (i+1) - pat);
        }
    }
}

int main () {
    freopen("inp.txt", "r", stdin);

    bool sep = false;
    while (cin >> n) {
        cin >> pattern >> text;
        if (pattern.size() > text.size())
            continue;
        if (sep) puts("");
        sep = true;
        lps();
        KMP();
    }

    return 0;
}
