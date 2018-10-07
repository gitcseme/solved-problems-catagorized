#include <iostream>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

int main() {   ios::sync_with_stdio(0); cin.tie(0); // Fast IO.

    int test_Case, n, snow, frn;
    long long max_pak, sz;
    pair<set<int>::iterator, bool> ret;
    cin >> test_Case;

    while (test_Case--) {
        cin >> n;
        set<int> uniq;
        deque<int> dq;
        max_pak = -1;
        while (n--) {
            cin >> snow;
            dq.push_back(snow);
            ret = uniq.insert(snow);
            if (!ret.second) {
                sz = uniq.size();
                max_pak = max (max_pak, sz);
                while (dq.front() != snow) {
                    frn = dq.front(); dq.pop_front();
                    uniq.erase(frn);
                }
                dq.pop_front();
            }
        }
        sz = uniq.size();
        max_pak = max (max_pak, sz);
        cout << max_pak << "\n";
    }

    return 0;
}
