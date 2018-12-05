#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

string C, c1, c2;
deque <int> dq;

int cube[7][5] = {
    {0, 0, 0, 0, 0},
    {0, 2, 3, 5, 4},
    {0, 4, 6, 3, 1},
    {0, 2, 6, 5, 1},
    {0, 5, 6, 2, 1},
    {0, 3, 6, 4, 1},
    {0, 5, 3, 2, 4}
};

bool match (int up) {
    dq.clear();

    for (int i = 1; i <= 4; ++i) dq.push_back(cube[up][i]);

    for (int i = 1; i <= 4; ++i) {
        string s = "X";
        s += c1[up];

        s += c1[dq[0]];
        s += c1[dq[1]];
        s += c1[dq[3]];
        s += c1[dq[2]];

        s += c1[7-up];

        if (s == c2) return true;
        int idx = dq.back(); dq.pop_back();
        dq.push_front(idx);
    }
    return false;
}

int main () {
    FI; FO;
    while (cin >> C) {
        c1 = c2 = "X";
        c1 += C.substr (0, 6);
        c2 += C.substr (6);

        bool f;
        for (int i = 1; i <= 6; ++i) {
            f = match(i);
            if (f) {
                cout << "TRUE\n";
                break;
            }
        }
        if (!f)
            cout << "FALSE\n";
    }

    return 0;
}
