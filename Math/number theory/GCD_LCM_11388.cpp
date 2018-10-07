#include <bits/stdc++.h>
using namespace std;

int main() {
    int G, L, a, b, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &G, &L);
        a = G;
        if (L % G != 0) {
            puts("-1");
            continue;
        }
        b = L;
        printf("%d %d\n", a, b);
    }

    return 0;
}
