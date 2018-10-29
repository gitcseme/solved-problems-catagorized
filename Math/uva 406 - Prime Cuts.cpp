#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
using namespace std;

#define N 1003
vector<int> P;
bool mark[N+2];

void Eratosthenes() {
    for(int i = 3; i * i <= N; i += 2)
        if (!mark[i])
            for (int j = i * i; j <= N; j += 2*i)
                mark[j] = true;

    P.push_back(1), P.push_back(2);
    for (int i = 3; i <= N; i += 2)
        if (!mark[i])
            P.push_back(i);
}

int main() {
    FI;

    Eratosthenes();

    int n, c, amt = P.size();
    while (scanf("%d %d", &n, &c) == 2)
    {
        printf("%d %d:", n, c);
        int len = upper_bound(P.begin(), P.end(), n) - P.begin();

        if (len % 2 == 0) c = 2 * c;
        else c = 2 * c - 1;
        if (c > len) c = len;

        for (int i = len/2 - c/2, j = 0; j < c; ++j, ++i)
            printf(" %d", P[i]);
        puts("\n");
    }

    return 0;
}
