#include <bits/stdc++.h>
using namespace std;

int N1, N2, a[105], b[105], mem[105][105];

int LCS (int i, int j) {
    if (i == N1 || j == N2) return 0;

    if (mem[i][j] != -1) return mem[i][j];

    int ans = 0;
    if (a[i] == b[j]) ans = 1 + LCS(i+1, j+1);
    else ans = max( LCS(i+1, j), LCS(i, j+1) );

    return mem[i][j] = ans;
}

int main () {
    freopen("inp.txt", "r", stdin);
    int cse = 0;
    while (scanf("%d %d", &N1, &N2) && (N1 && N2)) {
        memset(mem, -1, sizeof(mem));
        for (int i = 0; i < N1; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < N2; ++i) scanf("%d", &b[i]);
        printf("Twin Towers #%d\n", ++cse);
        printf("Number of Tiles : %d\n", LCS(0, 0));
        printf("\n");
    }

    return 0;
}
