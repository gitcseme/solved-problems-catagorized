#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int N, E;
string S, D;
map <string, string> parent;

struct Node {
    string u, v;
    int weight;
} edges[20000];

bool cmp (Node a, Node b) {
    return a.weight > b.weight;
}

string find_parent (string x) {
    if (parent[x] == "")
        return x;
    return parent[x] = find_parent(parent[x]);
}

int Kruskal () {
    sort(edges, edges + E, cmp);
    int ans = 99999999;
    string u, v;

    for (int i = 0; i < E; ++i) {
        u = find_parent(edges[i].u);
        v = find_parent(edges[i].v);
        if (u != v) {
            parent[v] = u;
            if (ans > edges[i].weight) {
                ans = edges[i].weight;
            }
        }
        if (find_parent(S) == find_parent(D)) {
            return ans;
        }
    }
}

int main() {
    //FI;

    int caseno = 0;
    while (cin >> N >> E && (N || E))
    {
        parent.clear();
        for (int i = 0; i < E; ++i)
            cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        cin >> S >> D;

        cout << "Scenario #" << ++caseno << "\n" << Kruskal() << " tons\n";
        puts("");
    }

    return 0;
}
