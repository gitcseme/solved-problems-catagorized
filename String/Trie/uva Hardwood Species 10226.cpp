#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    getchar();
    getchar();

    while (t--) {
        map <string, int> record;
        string tree;
        n = 0;
        while (getline(cin, tree)) {
            if (tree == "")
                break;
            record[tree]++;
            ++n;
        }
        for (map<string, int>::iterator it = record.begin(); it != record.end(); ++it) {
            cout << it->first << " " << fixed << setprecision(4) << (double)(it->second)*100.0 / n << "\n";
        }
        if (t) puts("");
    }
    return 0;
}
