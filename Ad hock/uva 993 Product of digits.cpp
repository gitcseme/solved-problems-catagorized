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
#define CIN         ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(NULL)
#define intlim      2147483648

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
    while (tc--) {
        int n = readInt();
        string ans;
        if (n == 0 || n == 1) pf("%d\n", n);
        else {
            for (int i = 9; i >= 2; --i) {
                if (n % i == 0) {
                    while (n % i == 0) {
                        ans += '0' + i;
                        n = n / i;
                    }
                }
            }

            if (n > 9) puts("-1");
            else {
                sort(all(ans));
                pf("%s\n", ans.c_str());
            }
        }
    }

    return 0;
}
