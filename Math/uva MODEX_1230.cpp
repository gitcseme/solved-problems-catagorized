#include <bits/stdc++.h>
using namespace std;

int bigmod(int a, int b, int M) {
    if (b == 0)
        return 1 % M;
    int x = bigmod(a, b/2, M);
    x = (x * x) % M;
    if (b & 1)
        x = (x * a) % M;
    return x;

}

int main () {
    int t, a, b, M;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &M);
        printf("%d\n", bigmod(a, b, M));
    }
    scanf("%d", &t);

    return 0;
}
