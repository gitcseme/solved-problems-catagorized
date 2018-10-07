#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main()
{
    int t, k, n;
    long long total;
    while (cin >> t, t) {

        total = 0;
        multiset<int> min_max;
        while (t--) {
            cin >> k;
            while (k--) {
                cin >> n;
                min_max.insert(n);
            }

            multiset<int>::iterator it;
            it = min_max.begin();
            int mi = *it;
            it = --min_max.end();
            int mx = *it;
            total += (mx - mi);

            min_max.erase(min_max.find(mi));
            min_max.erase(min_max.find(mx));
        }
        cout << total << "\n";
    }

    return 0;
}
