#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

int main () {
    //FI;

    int n, d, I;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> d >> I;
        int node = 1;

        while(d-- > 1) {
            if (I%2 == 1) {
                node = 2 * node;
                I = I / 2 + 1;
            }
            else {
                node = 2 * node + 1;
                I = I / 2;
            }
            if (I == 0) I = 1;
        }
        cout << node << "\n";
    }
    cin >> n;

    return 0;
}
