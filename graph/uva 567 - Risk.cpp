#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

vector <int> g[25];
bool vis[25];
int level[25];

void bfs (int src, int dest) {
    queue <int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    //FI;

    int N, X, j, caseno = 0, src, dest;

    while (scanf("%d", &X) != EOF) {
        for (int i = 0; i < X; ++i) {
            scanf("%d", &j);
            g[1].push_back(j);
            g[j].push_back(1);
        }
        for (int i = 2; i < 20; ++i) {
            scanf("%d", &X);
            for (int v = 0; v < X; ++v) {
                scanf("%d", &j);
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }

        scanf("%d", &N);
        printf("Test Set #%d\n", ++caseno);
        for (int i = 0; i < N; ++i) {
            memset(vis, 0, sizeof(vis));
            scanf("%d %d", &src, &dest);
            bfs(src, dest);
            printf("%2d to %2d: %d\n", src, dest, level[dest]);
        }
        printf("\n");
        for (int i = 1; i < 25; ++i) g[i].clear();
    }

    return 0;
}
