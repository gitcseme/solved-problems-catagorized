#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long

ULL mpow(ULL x, ULL y) {
    if(y == 0)   return 1;
    if(y&1)
        return x*mpow(x*x, y>>1);
    return mpow(x*x, y>>1);
}

int c[] = {
  4, 6, 8, 9, 10, 12, 14, 15, 16, 18,
  20, 21, 22, 24, 25, 26, 27, 28, 30,
  32, 33, 34, 35, 36, 38, 39, 40,
  42, 44, 45, 46, 48, 49, 50, 51, 52,
  54, 55, 56, 57, 58, 60, 62, 63, 64
};
set<ULL> out;

int main() {
    out.insert(1);
    for (int i = 2; i < 65536; ++i) {
        for (int j = 0; j < 45 && c[j] * log2(i) < 64; ++j) {
            out.insert(mpow(i, c[j]));
        }
    }

    for (auto it = out.begin(); it != out.end(); ++it)
        printf("%llu\n", *it);

    return 0;
}
