#include <bits/stdc++.h>
using namespace std;

int ori[25], b[25], N, mem[25][25];

int dp (int i, int j) {
    if (i == N || j == N) return 0;

    if (mem[i][j] != -1) return mem[i][j];

    int ans = 0;
    if (ori[i] == b[j]) ans = 1 + dp(i+1, j+1);
    else ans = max( dp(i+1, j), dp(i, j+1));

    return mem[i][j] = ans;
}

int main () {
    freopen("inp.txt", "r", stdin);
    scanf("%d", &N);
    int x;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &x);
        ori[x-1] = i;
    }

    while (1) {
        bool flag = false;
        memset(mem, -1, sizeof(mem));
        for (int i = 1; i <= N; ++i) {
            if(scanf("%d", &x) == 1)
                b[x-1] = i;
            else{
                flag = true;
                break;
            }
        }
        if (flag) break;
        printf("%d\n", dp(0, 0));
    }
    return 0;
}
