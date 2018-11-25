#include <bits/stdc++.h>
typedef long long Long;
using namespace std;

Long bigmod(Long a,Long b,Long M) {
    if (b == 0)
        return 1 % M;
    Long x = bigmod(a, b/2, M);
    x = (x * x) % M;
    if (b & 1) x = (x * a) % M;
    return x;
}

string Leading(Long n, Long k) {
    double x = k * log10(n*1.0);
    double c = x - (floor(x) + 1) + 3; // 3 leading digits.
    double ans = pow(10, c);

    return to_string(ans).substr(0, 3);
}

int main() {
    //freopen("inp.txt", "r", stdin);

    int tc;
    Long n, k;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%lld %lld", &n, &k);
        printf("%s...%03d\n", Leading(n, k).c_str(), bigmod(n, k, 1000));
    }

    return 0;
}
