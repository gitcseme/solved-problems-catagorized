#include <bits/stdc++.h>
#define all(x)      x.begin(),x.end()
#define ff          first
#define ss          second
#define len(a)       (int)a.size()
#define intlim      2147483647

#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

#define N 10104
vector<int> primes;
bool mark[N];

void Eratosthenes() {
    for(int i = 3; i * i <= N; i += 2)
        if (!mark[i])
            for (int j = i * i; j <= N; j += 2*i)
                mark[j] = true;

    primes.push_back(2);
    for (int i = 3; i <= N; i += 2)
        if (!mark[i])
            primes.push_back(i);
}


int main() {
    Eratosthenes();
    int tc, n;
    scanf("%d", &tc);
    for (int i = 0; i < tc; ++i) {
        scanf("%d", &n);
        int idx = (int)(upper_bound(all(primes), n/2) - primes.begin());
        printf("%d\n", primes[idx]);
    }

    return 0;
}

