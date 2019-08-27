#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

map<char, pair<int, int> > mat;

int main () {
    //FI;

    int n, p1, p2;
    char ch;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ch >> p1 >> p2;
        mat[ch] = {p1, p2};
    }

    string exp;
    while(cin >> exp) {
        stack<pair<int, int> > stk;
        long long ans = 0;
        bool err = false;
        for (int i = 0, len = exp.size(); i < len; ++i) {
            if (exp[i] == '(') continue;
            if (exp[i] == ')') {
                auto a = stk.top(); stk.pop();
                auto b = stk.top(); stk.pop();

                if (b.second == a.first) {
                    pair<int, int> p = {b.first, a.second};
                    ans = ans + b.first * b.second * a.second;
                    stk.push(p);
                }
                else {
                    err = true;
                    break;
                }
            }
            else {
                auto p = mat[exp[i]];
                stk.push(p);
            }
        }
        if (err) cout << "error\n";
        else cout << ans << "\n";
    }

    return 0;
}
