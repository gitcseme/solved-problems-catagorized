#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

const int mx = 105;
vector<int> adj[mx];
int d[mx], low[mx], timer = 0;

set<int> AP;

void init() {
    for (int i = 0; i < mx; ++i) {
        adj[i].clear();
        d[i] = -1;
        timer = 0;
    }
    AP.clear();
}

void find_bridge(int u, int p)
{
    low[u] = d[u] = timer++;
    int childCount = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (d[v] != -1) { // Back edge
            low[u] = min(low[u], d[v]);
        }
        else {
            find_bridge(v, u);
            low[u] = min(low[u], low[v]); // Take update
            if (low[v] >= d[u] && p != -1) {
                AP.insert(u);
            }
            ++childCount;
        }
    }
    if (p == -1 && childCount > 1) {
        AP.insert(u);
    }
}

int main() {
    FI;

    int n, u, v;
    string s;

    while (cin >> n, n) {
        init();
        while (getline(cin, s)) {
            if (s == "0") break;
            stringstream sso(s);
            sso >> u;
            while (sso >> v) {
                adj[u].emplace_back(v);
                adj[v].emplace_back(u);
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (d[i] == -1)
                find_bridge(i, -1);
        }
        printf("%d\n", AP.size());
    }

    return 0;
}

