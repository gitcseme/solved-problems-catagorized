#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[100005], n, q, l, r, x;

    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        arr[i] = arr[i-1];
        if (x==3 || x==4 || x==6)
            ++arr[i];
    }
    while (q--) {
        scanf("%d %d", &l, &r);
        printf("%d\n", arr[r] - arr[l-1]);
    }

    return 0;
}
