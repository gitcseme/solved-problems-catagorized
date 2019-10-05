#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {printf("%d ", i);} printf("\n");
#define what_is(x) cerr << #x << " = " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
/*---------------------------Codes-----------------------------*/

// MST + LCA

const int nax = 50004;
int N, M;
struct Edge {
    int a, b, w;
    Edge(int aa, int bb, int ww) {
        a = aa;
        b = bb;
        w = ww;
    }
    bool operator <(Edge &other) {
        return w < other.w;
    }
};
vector<Edge> g1;
vector<int> g[nax], cost[nax];
int dist[nax], L[nax], T[nax];

int parent[nax], renk[nax];

int find_parent(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_parent(parent[v]); // with path compression
}

void make_set(int v) {
    parent[v] = v;
    renk[v] = 0;
}

void union_sets(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a != b) {
        if (renk[a] < renk[b])
            swap(a, b);
        parent[b] = a;
        if (renk[a] == renk[b])
            renk[a]++;
    }
}

void Kruskal_Mst() {
    for (int i = 1; i <= N; ++i) make_set(i);
    sort(all(g1));

    for (Edge e : g1) {
        int x = e.a, y = e.b, z = e.w;
        if (find_parent(x) != find_parent(y)) {
            g[x].push_back(y);
            g[y].push_back(x);
            cost[x].push_back(z);
            cost[y].push_back(z);
            union_sets(x, y);
        }
    }
}

void bfs(int src) {
    memset(L, -1, sizeof(L));
    queue<int> q;
    dist[src] = 0; // src to src  distance = 0
    L[src] = 0;
    T[src] = -1;
    q.push(src);
    int u, v;

    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int i = 0; i < g[u].size(); ++i) {
            v = g[u][i];
            if (L[v] == -1) {
                T[v] = u;
                L[v] = 1 + L[u];
                dist[v] = cost[u][i];
                q.push(v);
            }
        }
    }
}

int P[nax][20];
int st_max[nax][20];

void build_table() {
    memset(P, -1, sizeof(P));
    for (int i = 1; i <= N; ++i) {
        P[i][0] = T[i];
        st_max[i][0] = dist[i];
    }

    for (int j = 1; (1 << j) <= N; ++j) {
        for (int i = 1; i <= N; ++i) {
            if (P[i][j-1] != -1) {
                P[i][j] = P[P[i][j-1]][j-1];
                st_max[i][j] = max(st_max[i][j-1], st_max[P[i][j-1]][j-1]);
            }
        }
    }
}

int lca(int a, int b) {
    if (L[a] < L[b]) swap(a, b);
    int log = floor(log2(L[a])) + 1;

    int ret = 0;
    // Pull L[a] to L[b]
    for (int j = log; j >= 0; --j) {
        if (L[a] - (1<<j) >= L[b]) {
            ret = max(ret, st_max[a][j]);
            a = P[a][j];
        }
    }

    if (a == b) return ret;

    for (int j = log; j >= 0; --j) {
        if (P[a][j] != -1 && P[a][j] != P[b][j]) {
            ret = max(ret, max(st_max[a][j], st_max[b][j]));
            a = P[a][j];
            b = P[b][j];
        }
    }

    ret = max(ret, max(dist[a], dist[b]));
    return ret;
}

void init() {
    g1.clear();
    for (int i = 0; i < nax; ++i) {
        g[i].clear();
        cost[i].clear();
    }
}

int main() {
    //FI;

    int tc, a, b, c, q, s, t;
    scanf("%d", &tc);

    for (int caseno = 1; caseno <= tc; ++caseno) {
        init();
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            g1.push_back(Edge(a, b, c));
        }

        Kruskal_Mst();
        bfs(1);
        build_table();

        scanf("%d", &q);
        printf("Case %d:\n", caseno);
        while(q--) {
            scanf("%d %d", &s, &t);
            printf("%d\n", lca(s, t));
        }
    }

    return 0;
}
