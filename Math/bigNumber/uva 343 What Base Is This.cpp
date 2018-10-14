#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
using namespace std;

int valueOf(char c) {
    if (c >= '0' && c <= '9') return (c - '0');
    if (c >= 'A' && c <= 'Z') return (c - 'A' + 10);
}

int main() {
    //FI;

    string s1, s2;
    vector <long long> v1, v2;

    while (cin >> s1 >> s2)
    {
        int m = 0, n = 0, p;
        v1.clear(); v2.clear();
        for (int i = 0; i < s1.size(); ++i) m = max(m, valueOf(s1[i]));
        for (int i = 0; i < s2.size(); ++i) n = max(n, valueOf(s2[i]));

        if (m == 0) ++m;
        if (n == 0) ++n;

        for (int base = m+1; base <= 36; ++base) {
            long long v = 0;
            p = 0;
            for (int i = s1.size()-1; i >= 0; --i)
                v += (int)round(pow(base, p++)) * valueOf(s1[i]);
            v1.push_back(v);
        }

        for (int base = n+1; base <= 36; ++base) {
            long long v = 0;
            p = 0;
            for (int i = s2.size()-1; i >= 0; --i)
                v += pow(base, p++) * valueOf(s2[i]);
            v2.push_back(v);
        }

        bool flag = true;
        for (int i = 0; i < v1.size() && flag; ++i) {
            for (int j = 0; j < v2.size(); ++j) {
                if (v1[i] == v2[j]) {
                    flag = false;
                    cout << s1 << " (base " << (m+1+i) << ") = " << s2 << " (base " << (n+1+j) <<")" << "\n";
                    break;
                }
            }
        }
        if (flag) cout << s1<<" is not equal to "<<s2 << " in any base 2..36" << "\n";
    }

    return 0;
}
