#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

#define N 200
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

set <pair<int, int>, greater<pair<int, int> > > S;

void factorize (int n) {
    int sq = sqrt(n) + 1, cnt;
    for (int i = 0; P[i] <= sq; ++i) {
        if (n % P[i] == 0) {
            cnt = 0;
            while (n % P[i] == 0) {
                ++cnt;
                n = n / P[i];
            }
            S.insert({P[i], cnt});
        }
    }
    if (n > 1) S.insert({n, 1});
}

int main () {
    Eratosthenes();
    string line;

    while (getline(cin, line)) {
        if (line[0] == '0') break;
        stringstream sso(line);
        int p, i, num = 1;
        while (sso >> p) {
            sso >> i;
            num = num * round( pow(p, i) );
        }
        num--;
        factorize(num);
        int len = S.size();
        for(pair<int, int> pii : S) {
            printf("%d %d", pii.first, pii.second);
            if (len != 1) putchar(' ');
            --len;
        }
        puts("");
        S.clear();
    }

    return 0;
}
