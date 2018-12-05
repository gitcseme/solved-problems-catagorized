#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define N 32000
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

int n, m;
map <int, int> totfact;
map <int, int> mfact;

void factorizeM (int x) {
    int cnt;
    for (int i = 0; (long long)primes[i] * primes[i] <= x; ++i) {
        cnt = 0;
        if (x % primes[i] == 0) {
            while (x % primes[i] == 0) {
                ++cnt;
                x /= primes[i];
            }
            if (cnt != 0) mfact[primes[i]] = cnt;
        }
    }
    if (x > 1) mfact[x] = 1;
}

bool IsRelevent (int i) {
    bool IR = true;
    int x = n - i + 1, y = i, cnt;
    for (map<int, int>::iterator p = mfact.begin(); p != mfact.end(); ++p)
    {
        cnt = 0;
        if (x % p->f == 0) {
            while (x % p->f == 0) {
                ++cnt;
                x /= p->f;
            }
            totfact[p->f] = totfact[p->f] + cnt;
        }
        cnt = 0;
        if (y % p->f == 0) {
            while (y % p->f == 0) {
                ++cnt;
                y /= p->f;
            }
            totfact[p->f] = totfact[p->f] - cnt;
        }
        if (totfact[p->f] < mfact[p->f])
            IR = false;
    }

    return IR;
}

int main () {
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    sieve();
    vector <int> notRelevent;
    while (scanf("%d %d", &n, &m) == 2) {
        n = n - 1; mfact.clear(); totfact.clear(); notRelevent.clear();
        factorizeM(m);
        for (int i = 1; i <= n; ++i) {
            if (IsRelevent(i))
                notRelevent.push_back(i+1);
        }
        int sz = notRelevent.size();
        printf("%d\n", sz);
        for (int i = 0; i < sz; ++i) {
            if (i != 0) printf(" ");
            printf("%d", notRelevent[i]);
        }

        puts("");
    }

    return 0;
}
