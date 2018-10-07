#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000006;
char pattern[MAXN];
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

int main() {
    freopen("inp.txt", "r", stdin);

    int t;
    scanf("%d", &t);
    for (int caseno = 1; caseno <= t; ++caseno) {
        scanf("%d", &n);
        scanf("%s", pattern);
        lps();
        printf("Test case #%d\n", caseno);
        for (int i = 1; i < n; ++i)
        {
            int len = i + 1;
            int root = len - suf[i];
            int k = len / root;
            if ( len % root == 0 && k > 1 ) {
                printf("%d %d\n", len, k);
            }
        }
        puts("");
    }

    return 0;
}
