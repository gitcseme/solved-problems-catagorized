#include <bits/stdc++.h>
#define pb          push_back
#define all(x)      x.begin(),x.end()
#define ms(a,v)     memset(a,v,sizeof a)
#define ff          first
#define ss          second
#define mp          make_pair
#define gc          getchar
#define pf          printf
#define sc          scanf
#define sz(a)       (int)a.size()
#define intlim      2147483647

#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int readInt () {
	bool minus = false; int result = 0; char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
    return minus ? -result : result;
}
/************************ Faster code *************************/

int main() {
    FI;

    int tc = readInt();
    int n;
    for (int caseno = 1; caseno <= tc; ++caseno) {
        n = readInt();
        int mx = 1, x;
        while (n--) {
            x = readInt();
            mx = max(mx, x);
        }
        pf("Case %d: %d\n", caseno, mx);
    }

    return 0;
}
