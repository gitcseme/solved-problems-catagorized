#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int main() {
    //FI;

    int start, p1, p2, p3;

    while (cin >> start >> p1 >> p2 >> p3) {
        if (start == 0 && p1==0 && p2==0 && p3==0)
            break;

        int degree = 2 * 360; // 2 full turns
        if (start < p1)  // Clock wise
            degree += (40 - (p1-start)) * 9;
        else
            degree += (start - p1) * 9;

        start = p1;
        degree += 360; // 1 full turn

        if (start < p2)
            degree += (p2 - start) * 9;
        else
            degree += (40 - (start - p2)) * 9;

        start = p2;

        if (start < p3)  // Clock wise
            degree += (40 - (p3 - start)) * 9;
        else
            degree += (start - p3) * 9;

        printf("%d\n", degree);
    }

    return 0;
}
