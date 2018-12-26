#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

struct Square {
    int r, c, level;
    Square (int rr, int cc) {
        r = rr;
        c = cc;
    }
};

int X[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int Y[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int board[8][8];

bool Is_valid (int r, int c) {
    if (r >= 0 && r < 8 && c >= 0 && c < 8) {
        if (board[r][c] == 0)
            return true;
        return false;
    }
    return false;
}

int bfs_2D(int sr, int sc, int dr, int dc) {
    if (sr == dr && sc == dc) return 0;

    queue <Square> q;
    Square src = Square(sr, sc);
    src.level = 0;
    board[src.r][src.c] = 1;
    q.push(src);

    while (!q.empty()) {
        Square u = q.front(); q.pop();
        for (int i = 0; i < 8; ++i) {
            if (Is_valid(u.r+X[i], u.c+Y[i])) {
                Square v = Square (u.r+X[i], u.c+Y[i]);
                v.level = u.level + 1;
                board[v.r][v.c] = 1;
                q.push(v);

                if ((v.r == dr) && (v.c == dc)) return v.level;
            }
        }
    }
}

int main() {
    //FI;

    string s;
    int sr, sc, dr, dc, ans;

    while (getline(cin, s)) {
        memset(board, 0, sizeof(board));
        sc = s[0] - 'a';
        sr = s[1] - '1';
        dc = s[3] - 'a';
        dr = s[4] - '1';

        ans = bfs_2D(sr, sc, dr, dc);
        cout << "To get from "<<s[0]<<s[1]<<" to "<<s[3]<<s[4]<<" takes "<<ans<<" knight moves.\n";
    }

    return 0;
}
