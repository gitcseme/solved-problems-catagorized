#include <iostream>
#include <cstring>
using namespace std;

int coin[] = {50, 25, 10, 5, 1};
int dp(int i, int x);
int mem[6][7500];

int main() { ios::sync_with_stdio(0); cin.tie(0);

    memset(mem, -1, sizeof(mem));
    int amount;
    while (scanf("%d", &amount) == 1) {
        int ways = dp(4, amount);
        printf("%d\n", ways);
    }

    return 0;
}

int dp(int i, int x) {
    if (x == 0) return 1;
    if (x < 0) return 0;
    if (i == -1) return 0;

    if (mem[i][x] != -1) return mem[i][x];

    int way1 = dp(i-1, x);
    int way2 = dp(i, x-coin[i]);

    return mem[i][x] = (way1 + way2);
}
