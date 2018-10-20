#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

int main () {
    FI;

    char c[110];
    while (1) {
        scanf("%s", c);
        if (c[0] == '0') break;
        int n, r = 0, len = strlen(c);

        for (int i = 0; i < len; i++) {
            n = r * 10 + (int) (c[i] - '0');
            r = n % 17;
        }
        if (r == 0) puts("1");
        else puts("0");
    }

    return 0;
}
