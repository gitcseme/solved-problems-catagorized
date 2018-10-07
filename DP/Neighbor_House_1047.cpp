#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
using namespace std;
#define INF 1<<28

typedef struct {
    int r, g, b;
} Color;
int n;
map<int, Color> cmap;
int mem[25][5];

int dp (int pre_color, int i) {
    if (i > n) return 0;
    if (mem[i][pre_color] != -1) return mem[i][pre_color];

    int res = INF;
    if (pre_color != 1) res = min(res, cmap[i].r + dp(1, i+1));
    if (pre_color != 2) res = min(res, cmap[i].g + dp(2, i+1));
    if (pre_color != 3) res = min(res, cmap[i].b + dp(3, i+1));

    return mem[i][pre_color] = res;
}

int main() {

    int T, cse=0;
    scanf("%d", &T);
    Color x;
    while(T--) {
        cmap.clear();
        memset(mem, -1, sizeof(mem));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &x.r, &x.g, &x.b);
            cmap[i] = x;
        }
        int answer = dp(-1, 1);
        printf("Case %d: %d\n", ++cse, answer);
    }
    return 0;
}
