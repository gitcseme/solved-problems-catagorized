#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

#define N 1001
vector<int> P;
bool mark[N];

void Eratosthenes() {
    for(int i = 3; i * i <= N; i += 2)
        if (!mark[i])
            for (int j = i * i; j <= N; j += 2*i)
                mark[j] = true;

    P.push_back(2);
    for (int i = 3; i <= N; i += 2)
        if (!mark[i])
            P.push_back(i);
}

bool isPrime(int n) {
    if(n == 2) return true;
    if (n < 2 || (n%2 == 0)) return false;
    return mark[n] == false;
}

bool isAnagramic (int p) {
    vector <int> a;
    while (p) {
        a.push_back(p%10);
        p = p / 10;
    }
    sort(a.begin(), a.end());
    int len = a.size();
    do {
        p = 0;
        for (int i = 0; i < len; ++i) p = p * 10 + a[i];
        if (!isPrime(p)) return false;
    } while (next_permutation(a.begin(), a.end()));
    return true;
}

int nextPow (int n) {
    int next = 1;
    while (n) {
        n = n / 10;
        next = next * 10;
    }
    return next;
}

int main () {
    Eratosthenes();
    vector <int> anaGmic;
    for (int i : P) if (isAnagramic(i)) anaGmic.push_back(i);

    int n;
    while (scanf("%d", &n), n)
    {
        int ans = 0;
        if (n < 1001) {
            for (int i : anaGmic) {
                if (i > n) {
                    ans = i;
                    break;
                }
            }
            if (ans && ans > nextPow(n)) ans = 0;
        }
        printf("%d\n", ans);
    }

    return 0;
}
