#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

#define N 32050
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

void print(int b, int e) {
    for (int i = b; i <= e-1; ++i)
        printf("%d ", primes[i]);
    printf("%d\n", primes[e]);
}

void DP(int x, int y) {
    int low = lower_bound(primes.begin(), primes.end(), x) - primes.begin();

    for (int i = low; primes[i+2] <= y; ++i)
    {
        if (primes[i+1]-primes[i] == primes[i+2]-primes[i+1]) {
            int b = i, e, j = i+2, d = primes[i+1]-primes[i];
            while (primes[j+1]-primes[j] == d) ++j;
            e = j;
            i = j - 1;

            if (primes[e] <= y) { // Check for a non-subset series.
                if (b == 0 || primes[b]-primes[b-1] != d)
                    print(b, e);
            }
        }
    }
}

int main() {
    //FI;

    Eratosthenes();
    int x, y;

    while (cin >> x >> y) {
        if (x==0 && y==0) break;
        if (x > y) swap(x, y);
        DP(x, y);
    }

    return 0;
}
