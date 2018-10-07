#include <iostream>
#include <cstring>
using namespace std;

int coin[] = {1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};
long long dp(int i, int x);
long long mem[25][10005];

int main() { ios::sync_with_stdio(0); cin.tie(0);

    memset(mem, -1, sizeof(mem));
    int amount;
    while (scanf("%d", &amount) == 1) {
        long long ways = dp(20, amount);
        printf("%lld\n", ways);
    }

    return 0;
}

long long dp(int i, int x) {
    if (x == 0) return 1;
    if (x < 0) return 0;
    if (i == -1) return 0;

    if (mem[i][x] != -1) return mem[i][x];

    long long way1 = dp(i-1, x);
    long long way2 = dp(i, x-coin[i]);

    return mem[i][x] = (way1 + way2);
}
