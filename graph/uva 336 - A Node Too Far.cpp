#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

typedef struct {
    int level;
    bool vis = false;
    vector <int> chield;
} Node;
map <int, Node> g;

int BFS (int src, int TTL) {
    int visited = 1;
    queue <int> q;
    q.push(src);
    g[src].vis = true;
    g[src].level = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (g[u].level == TTL) break;

        for (int v : g[u].chield) {
            if (!g[v].vis) {
                g[v].vis = true;
                g[v].level = g[u].level + 1;
                q.push(v);
                ++visited;
            }
        }
    }
    return visited;
}

int main() {
    //FI;

    int NC, u, v, src, TTL, total_nodes, visited, caseno = 0;
    while (scanf("%d", &NC) && NC) {
        for (int i = 0; i < NC; ++i) {
            scanf("%d %d", &u, &v);
            if (g.find(u) == g.end()) g[u] = Node();
            if (g.find(v) == g.end()) g[v] = Node();
            g[u].chield.push_back(v);
            g[v].chield.push_back(u);
        }

        total_nodes = g.size();
        while (scanf("%d %d", &src, &TTL)) {
            if (src == 0 && TTL == 0) break;
            visited = BFS(src, TTL);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++caseno, total_nodes-visited, src, TTL);

            for (auto it = g.begin(); it != g.end(); ++it) g[it->first].vis = false;
        }
        g.clear();
    }

    return 0;
}
