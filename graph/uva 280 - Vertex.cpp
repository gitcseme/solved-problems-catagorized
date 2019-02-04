#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

vector <int> g[105];
bool vis[105];

void dfs (int v) {
    for(int u : g[v]) {
        if (!vis[u]) {
            vis[u] = true;
            dfs(u);
        }
    }
}

int main() {
    //FI;
    int i, j, q, src, n, cnt;
    while (scanf("%d", &n) && n) {
        for(int c = 0; c < 105; ++c) g[c].clear();
        while (scanf("%d", &i) && i) {
            while(scanf("%d", &j) && j) {
                g[i].push_back(j);
            }
        }
        scanf("%d", &q);
        while (q-- > 0) {
            scanf("%d", &src);
            memset(vis, false, sizeof(vis));
            dfs(src);
            cnt = 0;
            vector<int> out;
            for (int c = 1; c <= n; ++c) if (!vis[c]){
                ++cnt;
                out.push_back(c);
            }

            printf("%d", cnt);
            if (cnt != 0) {
                putchar(' ');
                for(int c = 0; c <cnt; ++c) {
                    printf("%d", out[c]);
                    if (c < cnt - 1) putchar(' ');
                }
            }
            puts("");
        }
    }

    return 0;
}
