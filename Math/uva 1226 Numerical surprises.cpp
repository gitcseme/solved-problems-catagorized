#include <bits/stdc++.h>
using namespace std;

int main () {
    char P[2002];
    int d;
    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &d);
        getchar();
        scanf("%s", P);
        int len = strlen(P), n, r = 0;

        for (int i = 0; i < len; ++i) {
            n = r * 10 + (P[i] - '0');
            r = n % d;
        }
        printf("%d\n", r);
    }
    return 0;
}
