#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int main() {
    //FI;

    int n;

    while (cin >> n, n) {

        while (true) {
            int A = 1, block;
            queue<int> B;

            cin >> block;
            if (block == 0) {
                printf("\n");
                break;
            }
            B.push(block);
            for (int i = 1; i < n; ++i) {
                cin >> block;
                B.push(block);
            }

            bool success = true;
            stack<int> station;

            for (int i = 0; i < n; ++i) {
                int cur = B.front(); B.pop();
                if (!station.empty()) {
                    if (cur == station.top()) {
                        station.pop();
                    }
                    else {
                        if (cur < A) {
                            success = false;
                            goto answer;
                        }
                        else {
                            while (A <= n) {
                                int bring = A++;
                                if (cur == bring) {
                                    break;
                                }
                                else {
                                    station.push(bring);
                                }
                            }
                        }
                    }
                }
                else {
                    while (A <= n) {
                        int bring = A++;
                        if (cur == bring) {
                            break;
                        }
                        else {
                            station.push(bring);
                        }
                    }
                }
            }

            answer:
                if (success) printf("Yes\n");
                else printf("No\n");
        }
    }

    return 0;
}
