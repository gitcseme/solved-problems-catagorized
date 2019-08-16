#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

const double e = 2.71828182845904523536;
const double PI = 3.141592653589793239;
double dp[100005], eps = 1e-10;

// logB(x) = logC(x) / logC(B);
int getDigits(int N, int B) {
    if (N > 100000) {
        int res = (int)((log(sqrt(2*PI*N)) + N*log(N/e))/log(B))+1;
        return res;
    }
    return ceil(dp[N] / log(B) + eps);
}

int findZeros(int N, int B) {
    int zeros = INT_MAX, a, b, d;
    for (int p = 2; p <= B; p++) {
        if (B%p == 0) {
            a = 0;
            while (B%p == 0) { // a = frequency of p in B
                ++a;
                B = B / p;
            }

            b = 0, d = p;
            while(N/d != 0) { // b =  frequency of p in N
                b += N / d;
                d = d * p;
            }

            zeros = min(zeros, b/a);
        }
    }
    return zeros;
}

int main() {
    FI;
    int N, zeros, digits, B;

    for (int i = 1; i < 100005; i++)
        dp[i] = dp[i-1] + log(i);

    while (cin >> N >> B) {
        zeros = findZeros(N, B);
        digits = getDigits(N, B);

        printf("%d %d\n", zeros, digits);
    }

    return 0;
}
