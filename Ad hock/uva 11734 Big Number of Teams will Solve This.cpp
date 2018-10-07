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

string team, judge;
int tt, jj;

string removeSpace () {
    string s = "";
    for (int i = 0; i < tt; ++i) {
        if (isspace(team[i]))
            continue;
        s += team[i];
    }
    return s;
}

int main() {
    FI;

    int t;
    cin >> t;
    gc();

    for (int caseno = 1; caseno <= t; ++caseno) {
        getline(cin, team);
        getline(cin, judge);

        pf("Case %d: ", caseno);
        tt = team.size();
        jj = judge.size();
        if (team == judge) {
            puts("Yes");
            continue;
        }

        string team_No_space = removeSpace();
        if (team_No_space == judge) {
            puts("Output Format Error");
        }
        else {
            puts("Wrong Answer");
        }
    }

    return 0;
}
