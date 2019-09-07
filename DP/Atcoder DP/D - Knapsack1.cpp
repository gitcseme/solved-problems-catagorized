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
/* --------------------Code Bellow--------------------- */

long long W[105], V[105], mem[105][100005];
const int INF = 1e9 + 5;

long long knapsack(int i, int sack) {

    if (sack < 0) return -INF;
    if (i < 0) return 0;

    if (mem[i][sack] != -1) return mem[i][sack];

    long long ans1 = knapsack(i - 1, sack);
    long long ans2 = V[i] + knapsack(i - 1, sack - W[i]);

    return mem[i][sack] = max(ans1, ans2);
}

int main() {
    //FI;
    memset(mem, -1, sizeof(mem));

    int n, sack;
    scanf("%d %d", &n, &sack);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &W[i], &V[i]);
    }

    printf("%lld\n", knapsack(n-1, sack));

    return 0;
}
