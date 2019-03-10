#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int main() {
    //FI;
    int k, px, py, x, y;

    while (cin >> k, k) {
        cin >> px >> py;
        while (k--) {
            cin >> x >> y;
            if (px == x || py == y) {
                printf("divisa\n");
            }
            else if (x > px) { // E
                if (y > py) { // N
                    printf("NE\n");
                }
                else { // S
                    printf("SE\n");
                }
            }
            else { // W
                if (y > py) { // N
                    printf("NO\n");
                }
                else { // S
                    printf("SO\n");
                }
            }
        }
    }

    return 0;
}
