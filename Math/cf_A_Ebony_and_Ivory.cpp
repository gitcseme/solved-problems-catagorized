#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c; // ax + by = c.

    while (c > 0 && c%a != 0)
        c = c - b;
    cout << ( (c>=0) ? "Yes\n" : "No\n" );

    return 0;
}
