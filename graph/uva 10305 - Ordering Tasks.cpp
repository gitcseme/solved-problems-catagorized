#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

vector <int> node[105];
vector <int> output;
int indegree[105];
int n, m;


void topsort() {
    queue <int> q;
    for (int i = 1; i <= n; ++i) if (indegree[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        output.push_back(u);

        for (int v : node[u]) {
            --indegree[v];
            if (indegree[v] == 0)
                q.push(v);
        }
    }
}

int main() {
    //FI;

    int u, v;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        for (int i = 0; i < 105; ++i) {
            node[i].clear();
            indegree[i] = 0;
        }
        output.clear();

        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            node[u].push_back(v);
            ++indegree[v];
        }

        topsort();
        for(int i = 0, len = output.size(); i < len; ++i) {
            printf("%d", output[i]);
            if (i != len-1)
                putchar(' ');
        }
        puts("");
    }

    return 0;
}
