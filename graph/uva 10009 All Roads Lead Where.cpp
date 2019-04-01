#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

map <string, vector<string>> graph;
map <string, bool> visited;
map <string, string> parent;
string src;

void bfs(string s, string e) {
    queue <string> q;
    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        string u = q.front(); q.pop();
        if (u == e) return;

        for (string v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

void printPath (string s) {
    if (s == src) {
        printf("%c", s[0]);
        return;
    }
    printPath(parent[s]);
    printf("%c", s[0]);
}

int main () {
    //FI;

    int t, r, q;
    cin >> t;
    string a, b;

    while(t--) {
        cin >> r >> q;
        graph.clear();
        while (r--) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        while (q--) {
            visited.clear();
            parent.clear();
            cin >> a >> b;
            bfs(a, b);
            src = a;
            printPath(b);
            cout << "\n";
        }
        if (t) cout << "\n";
    }

    return 0;
}
