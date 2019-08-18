#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int main() {
    //FI;

    double H, U, D, F, pos, f;

    while(true) {
        cin >> H >> U >> D >> F;
        if (H == 0) break;

        int day = 0;
        pos = 0;
        f = (U * F) / 100;

        while (true) {
            ++day;
            pos += U;
            U -= f;
            if (U < 0) U = 0;

            if (pos > H) break;

            pos -= D;
            if (pos < 0) break;
        }

        if (pos < 0) cout << "failure on day " << day << "\n";
        else cout << "success on day " << day << "\n";
    }

    return 0;
}
