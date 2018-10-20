#include <bits/stdc++.h>
using namespace std;

#define N 100000000
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 2];
vector<int> primes;

void sieve() {
    int sqrtN = (int)sqrt((double)N) + 1;
    for (int i = 3; i <= sqrtN; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            for (int j = i*i; j <= N; j += 2*i)
                status[j>>6] = on(status[j>>6], ((j>>1) & 31));

    primes.push_back(2);
    for (int i = 3; i <= N; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            primes.push_back(i);
}

pair<int, int> getCord(int n) {
    int nth, row = 0, col, i = 1, x = 1;
    vector<int>::iterator itr = upper_bound(primes.begin(), primes.end(), n);
    nth = itr - primes.begin();

    while (x < nth) {
        ++row;
        x = x + (++i);
    }
    if (x >= nth) ++row;
    col = nth - (x - row);
    return make_pair(row, col);
}

int main() {
    sieve();
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n == 2) printf("1 1\n");
        else if (!(n&1))
            printf("-1\n");
        else {
            auto p = getCord(n);
            printf("%d %d\n", p.first, p.second);
        }
    }

    return 0;
}
