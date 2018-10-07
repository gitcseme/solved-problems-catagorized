#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define INF 20000000

int N;
int dimond[250][150];
int dp(int i, int j);
bool is_valid(int i, int j);
int mem[250][150];

int main() {
    int T, tc = 0;
    scanf("%d", &T);
    while (T--) {
        memset(dimond, 0, sizeof(dimond));
        memset(mem, -1, sizeof(mem));
        scanf("%d", &N);
        for (int i = 0; i < 2*N-1; ++i) {
            if (i < N)
                for (int j = 0; j <= i; ++j) scanf("%d", &dimond[i][j]);
            else
                for (int j = 0; j < 2*N-i-1; ++j) scanf("%d", &dimond[i][j]);
        }

        int res = dp(0, 0);
        printf("Case %d: %d\n", ++tc, res);
    }

    return 0;
}

int dp(int i, int j) {
    if(!is_valid(i, j)) return 0;

    if (mem[i][j] != -1) return mem[i][j];

    int ret = -INF;
    ret = max(ret, dimond[i][j] + dp(i+1, j));
    if (i < N-1)
        ret = max(ret, dimond[i][j] + dp(i+1, j+1));
    else
        ret = max(ret, dimond[i][j] + dp(i+1, j-1));
    return mem[i][j] = ret;
}

bool is_valid(int i, int j) {
    if (i < 2*N-1 && j < N && j >= 0)
        return true;
    else return false;
}
