#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

#define MP make_pair

typedef pair<int, int> pii;
typedef vector<pii> vpii;

struct comp {
    bool operator() (pii p1, pii p2) {
        if (p1.second > p2.second) return true;
        else if (p1.second < p2.second) return false;
        else return (p1.first > p2.first) ? true : false;
    }
};

int main() { ios::sync_with_stdio(0); cin.tie(0);

    priority_queue<pii, vpii, comp> pq;
    map<int, int> basic;
    string reg;
    int k, query_num, period;

    while (1) {
        cin >> reg;
        if (reg[0] == '#') break;
        cin >> query_num >> period;
        pq.push(MP(query_num, period));
        basic.insert(MP(query_num, period));
    }

    cin >> k;
    for (int i = 0; i < k; ++i) {
        pii p = pq.top();
        cout << p.first << "\n";
        pq.pop();
        pq.push(MP(p.first, p.second+basic[p.first]));
    }

    return 0;
}
