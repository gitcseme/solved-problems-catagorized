#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); // Fast IO.
    map <string, int> hay;
    string str, desc;
    int m, n, val;
    long long salary;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> str >> val;
        hay.insert(make_pair(str, val));
    }

    for (int i = 0; i < n; i++) {
        salary = 0;

        while(1) {
            cin >> desc;
            if (desc == ".") break;
            salary += hay[desc];
        }
        cout << salary << "\n";
    }

    return 0;
}
