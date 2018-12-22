#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int R, C;
int grid[1005][1005];
int X[] = {0, 0, -1, 1};
int Y[] = {-1, 1, 0, 0};

struct Point {
    int r, c, level;
    Point (int rr, int cc) {
        r = rr;
        c = cc;
    }
};

bool IsValid(int i, int j) {
    if (i >= 0 && i < R && j >= 0 && j < C) return true;
    return false;
}

int bfs_2D(Point src, Point dest) {
    queue <Point> q;
    src.level = 0;
    q.push(src);

    while (!q.empty())
    {
        Point u = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            if (IsValid(u.r+X[i], u.c+Y[i]) && grid[u.r+X[i]][u.c+Y[i]] == 0) {
                Point v = Point(u.r+X[i], u.c+Y[i]);
                v.level = u.level + 1;
                grid[v.r][v.c] = 1;
                if ((v.r == dest.r) && (v.c == dest.c))
                    return v.level;
                q.push(v);
            }
        }
    }
}

int main() {
    //FI;
    int n, r, booms, c, src, dest;

    while (scanf("%d %d", &R, &C) && (R && C)) {
        memset(grid, 0, sizeof(grid));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &r, &booms);
            for (int j = 0; j < booms; ++j) {
                scanf("%d", &c);
                grid[r][c] = 1;
            }
        }
        scanf("%d %d", &r, &c);
        Point src = Point(r, c);
        scanf("%d %d", &r, &c);
        Point dest = Point(r, c);

        printf("%d\n", bfs_2D(src, dest));
    }

    return 0;
}
