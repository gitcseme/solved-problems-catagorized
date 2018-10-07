#include <bits/stdc++.h>
using namespace std;

#define N 3005
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 2];

int sieve(int n) {
    vector<int> almost[n+2];
    int sqrtN = (int)(sqrt((double)n) + 1), cnt = 0;
    for (int i = 3; i <= sqrtN; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            for (int j = i*i; j <= n; j += 2*i)
                status[j>>6] = on(status[j>>6], ((j>>1) & 31));

    for (int i = 2; i <= n; i += 2) {
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            for (int j = i; j <= n; j += i) almost[j].push_back(i);
        if (i == 2) --i;
    }
    for (int i = 2; i <= n; ++i) if (almost[i].size() == 2) ++cnt;
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", sieve(n));

    return 0;
}
