#include <bits/stdc++.h>
using namespace std;

#define N 33000
bool mark[N];

void Eratosthenes() {
    for(int i = 3; i * i <= N; i += 2)
        if (!mark[i])
            for (int j = i * i; j <= N; j += 2*i)
                mark[j] = true;

}

bool isPrime (int n) {
    if (n == 2) return true;
    if (n < 2 || n%2 == 0) return false;
    return mark[n] == false;
}

int main () {
    Eratosthenes();
    int n, b, e, cnt;

    while (scanf("%d", &n), n)
    {
        cnt = 0;
        b = 2; e = n-2;
        while (b <= e) {
            if (isPrime(b) && isPrime(e))
                ++cnt;
            ++b, --e;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
