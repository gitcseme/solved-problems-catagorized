#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 200000000
int p[1005];
int w[1005];
int mem[1002][3002];
int KnapSack(int i, int sack);

int main() { ios::sync_with_stdio(0); cin.tie(0);
    int tc, N, G, sale, wt;
    scanf("%d", &tc);

    while (tc--) {
        scanf("%d", &N);
        for(int i = 0; i < N; ++i) scanf("%d %d", &p[i], &w[i]);
        scanf("%d", &G);
        sale = 0;
        memset(mem, -1, sizeof(mem));
        for(int i = 0; i < G; ++i) {
            scanf("%d", &wt);
            sale += KnapSack(N-1, wt);
        }
        printf("%d\n", sale);
    }
    return 0;
}

int KnapSack(int i, int sack) {
    if (sack < 0) return -INF;
    if (i < 0) return 0;
    if (mem[i][sack] != -1) return mem[i][sack];

    int ans1 = KnapSack(i-1, sack);
    int ans2 = p[i] + KnapSack(i-1, sack - w[i]);

    return mem[i][sack] = max(ans1, ans2);
}
