#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
vector<int> vec[MAXN + 1];
bool mark[MAXN];

void preCall() {
    for (int i = 2; i <= MAXN; ++i) {
        if (!mark[i]) {
            for (int j = i; j <= MAXN; j += i) {
                vec[j].push_back(i);
                mark[j] = true;
            }
        }
    }
}

int main() {
    preCall();
    int n, x = 1, fac = 1;
    cin >> n;
    bool f = true;
    for (int i : vec[n]) {
        if ((i*n) % (i-1) == 0) {
            x = x * (i * n) / (i-1);
            fac = fac * i;
        }
        else {
            cout << "-1\n";
            f = false;
            break;
        }
    }
    if (f) cout << x / fac;

    return 0;
}
