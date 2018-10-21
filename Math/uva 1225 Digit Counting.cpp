#include <bits/stdc++.h>
using namespace std;

const int mx = 10004;
int d[mx][11];
int a[11];

void cnt (int n) {
    for(int i = 0; i <= 9; ++i) a[i] = 0;
    while(n != 0) {
        ++a[n % 10];
        n = n / 10;
    }
}

int main() {
    memset(d, 0, sizeof(d));

    d[1][1] = 1;
    for (int i = 2; i < mx; ++i) {
        cnt(i);
        for (int j = 0; j <= 9; ++j)
            d[i][j] = d[i-1][j] + a[j];
    }

    int tc, N;
    scanf("%d", &tc);
    for (int i = 0; i < tc; ++i) {
        scanf("%d", &N);
        for (int c = 0; c <= 9; ++c) {
            printf("%d", d[N][c]);
            if (c != 9) putchar(' ');
        }
        puts("");
    }

    return 0;
}







