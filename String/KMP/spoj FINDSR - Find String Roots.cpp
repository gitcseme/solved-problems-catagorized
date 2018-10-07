#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
char pattern[MAXN];
int suf[MAXN];

int lps (int l) {
    int len = l, k = 0; suf[0] = 0;
    for (int i = 1; i < len; ++i) {
        while (k > 0 && pattern[k] != pattern[i])
            k = suf[k - 1];
        if (pattern[k] == pattern[i])
            ++k;
        suf[i] = k;
    }
    return suf[len-1];
}

int main () {
    freopen("inp.txt", "r", stdin);

    while (1) {
        scanf("%s", pattern);
        if (pattern[0] == '*') break;
        int len = strlen(pattern);
        int match = lps(len);
        if (len % (len-match) == 0) {
            printf("%d\n", len /(len-match));
        }
        else puts("1");
    }

    return 0;
}
