#include <bits/stdc++.h>
using namespace std;

int main () { ios::sync_with_stdio(0); cin.tie(0);
    //freopen("zzz.txt", "r", stdin);
    double d;
    vector <double> vec;
    while (cin >> d) vec.push_back(d);

    for (int i = vec.size() - 1; i >= 0; --i)
        cout << fixed << setprecision(4) << sqrt(vec[i]) << "\n";

    return 0;
}
