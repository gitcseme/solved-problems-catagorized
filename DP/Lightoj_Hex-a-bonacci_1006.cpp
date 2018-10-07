#include <stdio.h>
#include <cstring>
int mem[10005];
int a, b, c, d, e, f;
long long fn( int n ) {
    if(n < 0) return 0;
    if (mem[n] != -1)
        return mem[n];
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    return mem[n] = (fn(n-1)%10000007 + fn(n-2)%10000007 + fn(n-3)%10000007 + fn(n-4)%10000007 + fn(n-5)%10000007 + fn(n-6)%10000007)%10000007;
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        memset(mem, -1, sizeof(mem));
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %lld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
