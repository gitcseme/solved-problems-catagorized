#include <bits/stdc++.h>
using namespace std;
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {printf("%d ", i);} printf("\n");
#define what_is(x) cerr << #x << " = " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
/*---------------------------Codes-----------------------------*/

const int nax = 1005;
const int mod = 1e9 + 7;
int R, C;
char grid[nax][nax];
long long mem[nax][nax];

long long dp(int i, int j) {
    if (i == R-1 && j == C-1) return 1;

    if (mem[i][j] != -1) return mem[i][j];

    long long ans1 = 0, ans2 = 0;
    if (i < R-1 && grid[i+1][j] == '.') {
        ans1 = dp(i + 1, j);
    }
    if (j < C-1 && grid[i][j+1] == '.') {
        ans2 = dp(i, j + 1);
    }

    return mem[i][j] = (ans1%mod + ans2%mod) % mod;
}

int main() {
    FI;

    memset(mem, -1, sizeof(mem));
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; ++i) {
        scanf("%s", grid[i]);
    }

    long long ans = dp(0, 0);
    printf("%lld\n", ans);

    return 0;
}
