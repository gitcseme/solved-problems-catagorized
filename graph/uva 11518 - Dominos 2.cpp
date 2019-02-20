#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int n, m, l;
vector <int> g[10004];
bool vis[10004];
vector <int> hand;

void dfs (int u) {
    vis[u] = true;
    for (int v : g[u])
        if (!vis[v])
            dfs(v);
}

int main() {
    //FI;

    int t, x, y, z;
    cin >> t;

    while (t--) {
        for (int i = 1; i <= n; ++i) { g[i].clear(); vis[i] = false; }
        hand.clear();

        cin >> n >> m >> l;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            g[x].push_back(y);
        }
        for (int i = 0; i < l; ++i) {
            cin >> z;
            hand.push_back(z);
        }

        for (int i = 0; i < l; ++i) {
            if (!vis[hand[i]]) {
                dfs(hand[i]);
            }
        }
        int not_vis = 0;
        for (int i = 1; i <= n; ++i)
            if (!vis[i])
                ++not_vis;

        cout << (n-not_vis) << "\n";
    }

    return 0;
}
