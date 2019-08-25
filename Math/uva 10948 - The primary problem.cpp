#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

#define N 1000006
bool mark[N];

void Eratosthenes() {
    mark[0] = mark[1] = true;
    for(int i = 3; i * i <= N; i += 2)
        if (!mark[i])
            for (int j = i * i; j <= N; j += 2*i)
                mark[j] = true;
}

bool isP(int p) {
    if (p == 2) return true;
    if (p%2 == 0) return false;
    return mark[p] == false;
}

int x, y;

bool GoldBatch(int n) {
    for (int i = 2, j = n-2; i <= j; ++i,--j) {
        if (isP(i) && isP(j)) {
            x = i;
            y = j;
            return true;
        }
    }
    return false;
}

int main() {
    Eratosthenes();
    int n;
    while (cin >> n, n) {
        if (GoldBatch(n)) {
            printf("%d:\n%d+%d\n", n, x, y);
        }
        else printf("%d:\nNO WAY!\n", n);
    }

    return 0;
}
