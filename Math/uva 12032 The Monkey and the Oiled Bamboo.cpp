#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n;
int arr[MAXN];

int monkey (int mx) {
    int k = mx, ans = mx;
    for (int i = 1; i <= n; ++i) {
        if (arr[i] - arr[i-1] == k) {
            --k;
        }
        else if(arr[i] - arr[i-1] > k) {
            ++ans;
            break;
        }
    }
    return ans;
}

int main () {
    freopen("inp.txt", "r", stdin);

    int t;
    scanf("%d", &t);
    for (int caseno = 1; caseno <= t; ++caseno) {
        scanf("%d", &n);
        int k = 0;
        arr[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
            if (arr[i] - arr[i-1] > k)
                k = arr[i] - arr[i-1];
        }

        printf("Case %d: %d\n", caseno, monkey(k));
    }

    return 0;
}
