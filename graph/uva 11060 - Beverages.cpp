#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int n, m;

struct Node {
    string name;
    int indegree, order;
    vector <string> adj;

    Node () {}
    Node (string d) {
        name = d;
        indegree = 0;
    }
};

map <string, Node> g;
vector <string> output;

bool operator <(Node s1, Node s2) {
    return s1.order > s2.order;
}

void topsort() {
    priority_queue <Node> q;
    for (auto it = g.begin(); it != g.end(); ++it) {
        if (it->second.indegree == 0) q.push(it->second);
    }

    while (!q.empty()) {
        Node u = q.top(); q.pop();
        output.push_back(u.name);

        for (string s : u.adj) {
            g[s].indegree--;
            if (g[s].indegree == 0) q.push(g[s]);
        }
    }
}

int main() {
    //FI;

    string s1, s2;
    int caseno = 0, k;

    while (cin >> n) {
        g.clear();
        output.clear();
        k = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s1;
            g[s1] = Node(s1);
            g[s1].order = ++k;
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> s1 >> s2;
            g[s2].indegree++;
            g[s1].adj.push_back(s2);
        }

        topsort();

        cout << "Case #"<<++caseno<<": Dilbert should drink beverages in this order: ";
        for (int i = 0, len = output.size(); i < len; ++i) {
            cout << output[i];
            if (i != len-1) putchar(' ');
        }
        puts(".\n");
    }

    return 0;
}
