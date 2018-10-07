#include <iostream>
#include <cstring>
using namespace std;

const int mod = 100000000;
int n1, n2, a, b;
int mem[101][101][11][11];
int dp(int n1, int n2, int k1, int k2) {
    if(n1<0 || n2<0 || k1<0 || k2<0) return 0;
    if(!n1 && !n2) return 1;

    if (mem[n1][n2][k1][k2] != -1) return mem[n1][n2][k1][k2];

    int ans1 = dp(n1-1, n2, k1-1, b) % mod;
    int ans2 = dp(n1, n2-1, a, k2-1) % mod;

    return mem[n1][n2][k1][k2] = (ans1+ans2) % mod;
}

int main() { ios::sync_with_stdio(0); cin.tie(0);
    cin >> n1 >> n2 >> a >> b;
    memset(mem, -1, sizeof(mem));
    cout << dp(n1, n2, a, b) << endl;
    return 0;
}
