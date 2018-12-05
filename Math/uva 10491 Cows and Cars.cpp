#include <bits/stdc++.h>
using namespace std;

int main () {
    int cow, car, show, a, b, x, y;
    while (scanf("%d %d %d", &cow, &car, &show) != EOF) {
        int total = cow + car;

        a = cow * car;
        b = total * (total - (show + 1));
        x = car * (car - 1);
        y = total * (total - (show + 1));

        double ans = ((double)a / b) + ((double)x / y);
        printf("%.5f\n", ans);
    }

    return 0;
}
