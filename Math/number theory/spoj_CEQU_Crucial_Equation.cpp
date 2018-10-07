#include <cstdio>
#include <stdlib.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
    int T, a, b, c, cse = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        if (c % gcd(abs(a), abs(b)) == 0)
            printf("Case %d: Yes\n", ++cse);
        else
            printf("Case %d: No\n", ++cse);
    }

    return 0;
}
