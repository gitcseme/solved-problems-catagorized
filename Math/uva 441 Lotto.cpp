#include <bits/stdc++.h>
using namespace std;

int a[15], k;
vector <int> ans;

void printSol () {
    for (int i = 0; i < 6; ++i) {
        printf("%d", ans[i]);
        if (i < 5) printf(" ");
    }
    puts("");
}

void backtrack (int i) {

    if (ans.size() == 6) {
        printSol();
        return;
    }
    if (i == k) return;

    ans.push_back(a[i]);
    backtrack(i+1);
    ans.pop_back();
    backtrack(i+1);
}

int main () {
    freopen("inp.txt", "r", stdin);
    bool sep = false;
    while (cin >> k && k) {
        if (sep) puts("");
        sep = true;

        for (int i = 0; i < k; ++i) cin >> a[i];
        ans.clear();
        backtrack(0);
    }

    return 0;
}
