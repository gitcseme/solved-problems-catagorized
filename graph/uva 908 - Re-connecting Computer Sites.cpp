#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int M, k;
struct Node {
    int u, v, w;
} edges[1000006];
int parent[1000006], renk[1000006];

bool cmp (Node a, Node b) {
    return a.w < b.w;
}

int find_parent (int v) {
    if (parent[v] == 0)
        return v;
    return parent[v] = find_parent(parent[v]);
}

void union_sets (int a, int b) {
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

long long Kruskal (int turn) {
    int T = turn == 1 ? M : M+k;
    sort(edges, edges + T, cmp);
    long long cost = 0;

    for (int i = 0; i < T; ++i) {
        if (find_parent(edges[i].u) != find_parent(edges[i].v)) {
            cost += edges[i].w;
            union_sets(edges[i].u, edges[i].v);
        }
    }
    return cost;
}

int main() {
    //FI;

    int N, x, y, z;
    long long cost = 0;
    bool sep = false;
    while (scanf("%d", &N) == 1)
    {
        memset(parent, 0, sizeof(parent));
        memset(renk, 0, sizeof(renk));
        if (sep) puts("");
        sep = true;

        for (int i = 0; i < N-1; ++i) scanf("%d %d %d", &x,&y,&z);
        scanf("%d", &k);
        int a[k][3];
        for (int i = 0; i < k; ++i) scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
        scanf("%d", &M);
        for (int i = 0; i < M; ++i) scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

        printf("%lld\n", Kruskal(1));
        memset(parent, 0, sizeof(parent));
        memset(renk, 0, sizeof(renk));

        for (int i = 0; i < k; ++i) {
            edges[M+i].u = a[i][0];
            edges[M+i].v = a[i][1];
            edges[M+i].w = a[i][2];
        }
        printf("%lld\n", Kruskal(2));
    }

    return 0;
}
