#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000006;

char text[MAXN], pattern[MAXN];
int suf[MAXN];

void lps () {
    int len = strlen(pattern), k = 0;
    for (int i = 1; i < len; ++i) {
        while (k > 0 && pattern[k] != pattern[i])
            k = suf[k - 1];
        if (pattern[k] == pattern[i])
            ++k;
        suf[i] = k;
    }
}

int KMP () {
    int len = strlen(text), k = 0, pat = strlen(pattern), freq = 0;
    for (int i = 0; i < len; ++i) {
        while (k > 0 && pattern[k] != text[i])
            k = suf[k - 1];
        if (pattern[k] == text[i])
            ++k;
        if (k == pat) {
            k = suf[k-1]; // advance technique to get all.
            ++freq;
        }
    }
    return freq;
}

int main () {
    freopen("inp.txt", "r", stdin);

    int t;
    scanf("%d", &t);
    for (int caseno = 1; caseno <= t; ++caseno) {
        scanf("%s", text);
        scanf("%s", pattern);
        lps();
        int freq = KMP();
        printf("Case %d: %d\n", caseno, freq);
    }

    return 0;
}
