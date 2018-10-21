#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;
#define N 300
bool mark[N+3];
vector<int> primes;

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
    //FI;
    Eratosthenes();
    int n, d, cnt, SOD;
    bool f = true;

    while (scanf("%d", &n) && n)
    {
        if (f) printf("PERFECTION OUTPUT\n");
        f = false;

        if (n == 1) {
            printf("%5d  DEFICIENT\n", n);
            continue;
        }
        d = n;
        SOD = 1;
        for (int p : primes) {
            if (p * p > d) break;
            if (n % p == 0) {
                cnt = 0;
                while (n % p == 0) {
                    n = n / p;
                    ++cnt;
                }
                SOD = SOD * (pow(p, cnt+1) - 1) / (p-1);
            }
        }
        if (n > 1) SOD = SOD * (round((pow(n, 2)) - 1) / (n-1));

        SOD = SOD - d;

        if (SOD == d) printf("%5d  PERFECT\n", d);
        else if (SOD < d) printf("%5d  DEFICIENT\n", d);
        else printf("%5d  ABUNDANT\n", d);

    }
    printf("END OF OUTPUT\n");

    return 0;
}
