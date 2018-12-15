#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

const int MAXN = 202;
#define W 0
#define B 1
#define R 2

vector <int> g[MAXN];
int color[MAXN];

bool Is_Bicolorable (int source) {
    queue <int> q;
    q.push(source);
    color[source] = B;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (color[v] == W) {
                if (color[u] == R) color[v] = B;
                else color[v] = R;
                q.push(v);
            }
            else if (color[v] == color[u]) return false;
        }
    }
    return true;
}

int main() {
    //FI;
    int n, l, u, v;

    while (scanf("%d %d", &n, &l) && n) {
        memset(color, W, sizeof(color));
        for (int i = 0; i < MAXN; ++i) g[i].clear();

        for (int i = 0; i < l; ++i) {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if (Is_Bicolorable(0)) puts("BICOLORABLE.");
        else puts("NOT BICOLORABLE.");
    }

    return 0;
}
