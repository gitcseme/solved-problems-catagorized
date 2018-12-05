#include <bits/stdc++.h>
using namespace std;

vector <int> ans;

void solve (int n) {
    if (n == 0) cout << "10\n";
    else if (n == 1) cout << "1\n";
    else {
        for (int i = 9; i >= 2; --i) {
            if (n % i == 0) {
                while (n % i == 0) {
                    ans.push_back(i);
                    n = n / i;
                }
            }
        }
        if (n == 1) {
            for (int i = ans.size() - 1; i >= 0; --i)
                cout << ans[i];
            cout << "\n";
        }
        else cout << "-1\n";
    }
}

int main () {
    int n;
    cin >> n;
    solve(n);

    return 0;
}
