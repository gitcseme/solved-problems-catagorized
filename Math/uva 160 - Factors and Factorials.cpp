#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

#define N 105
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

vector<int> getPrimeFactor(int n) {
    vector<int> ret;
    for (int i = 0; i < primes.size() && primes[i] <= n; i++) {

        int p = primes[i], cnt = 0;
        while(n/p != 0) {
            cnt += n/p;
            p = p * primes[i];
        }
        ret.push_back(cnt);
    }

    return ret;
}

int main() {
    Eratosthenes();
    int n, cnt;
    while (cin >> n, n) {
        vector<int> P = getPrimeFactor(n);
        printf("%3d! =", n);
        cnt = 0;
        for (int i = 0; i < P.size(); i++) {
            if (cnt == 15) {
                cnt = 0;
                printf("\n      ");
            }

            printf("%3d", P[i]);
            ++cnt;
        }
        printf("\n");
    }

    return 0;
}
