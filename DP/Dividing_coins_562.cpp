#include <iostream>
#include <cstring>
using namespace std;
#define INF 200000000;

int wt[105];
int mem[105][125005];
int KnapSack(int i, int sack);

int main() { ios::sync_with_stdio(0); cin.tie(0);

    int tc, m, sum;
    scanf("%d", &tc);

    while (tc--) {
        memset(mem, -1, sizeof(mem));
        scanf("%d", &m);
        sum = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%d", &wt[i]);
            sum += wt[i];
        }
        int benifit = KnapSack(m-1, sum/2);
        printf("%d\n", sum - 2 * benifit);
    }
    return 0;
}

int KnapSack(int i, int sack) {
    if (sack < 0) return -INF;
    if (i < 0)    return 0;

    if (mem[i][sack] != -1) return mem[i][sack];

    int ans1 = KnapSack(i-1, sack);
    int ans2 = wt[i] + KnapSack(i-1, sack - wt[i]);

    return mem[i][sack] = max(ans1, ans2);
}
