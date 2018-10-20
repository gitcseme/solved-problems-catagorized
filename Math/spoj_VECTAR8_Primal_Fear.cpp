#include <bits/stdc++.h>
using namespace std;

#define N 1000000
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 2];

void sieve() {
    int sqrtN = (int)sqrt((double)N) + 1;
    for (int i = 3; i <= sqrtN; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            for (int j = i*i; j <= N; j += 2*i)
                status[j>>6] = on(status[j>>6], ((j>>1) & 31));
}

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(n&1)) return false;
    return check(status[n>>6], ((n>>1) & 31)) == 0;
}

bool valid(int n) {
    if (isPrime(n)) {
        if (n < 10) return true;
        string s, st = to_string(n);
        if (st.find("0") != string::npos) return false;
        int x, len = st.size();
        for (int i = 1; i < len; ++i) {
            s = st.substr(i);
            stringstream sso(s);
            sso >> x;
            if (!isPrime(x)) return false;
        }
        return true;
    }
    return false;
}

vector<int> fear_primes;
void fear() {
    fear_primes.push_back(2);
    for (int i = 3; i <= N; i += 2) {
        if(valid(i))
            fear_primes.push_back(i);
    }
}

int main() {
    sieve();
    fear();
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector<int>::iterator pos = upper_bound(fear_primes.begin(), fear_primes.end(), n);
        printf("%d\n", pos-fear_primes.begin());
    }

    return 0;
}
