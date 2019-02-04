#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

vector <int> g[100010];
bool vis[100010];
stack <int> stk;

void dfs2 (int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v])
            dfs2(v);
    }
    stk.push(u);
}

void dfs1(int u) {
    vis[u] = true;
    for (int v : g[u])
        if (!vis[v])
            dfs1(v);
}

int main() {
    //FI;

    int t, x, y, m, n;
    scanf("%d", &t);
    while (t--) {
        memset(vis, false, sizeof(vis));

        scanf("%d %d", &n, &m);
        while (m--) {
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
        }

        for (int i = 1; i <= n; ++i) if (!vis[i]) dfs2(i);

        memset(vis, false, sizeof(vis));
        int cnt = 0;
        while (!stk.empty()) {
            int u = stk.top();
            stk.pop();
            if (!vis[u]) {
                ++cnt;
                dfs1(u);
            }
        }

        printf("%d\n", cnt);
        for (int i = 1; i <= n; ++i) g[i].clear();
    }

    return 0;
}
