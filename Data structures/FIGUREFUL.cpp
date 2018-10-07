#include <iostream>
#include <map>
using namespace std;

int main() {
    int c1, c2, t, test;
    string name;
    map <pair<int, int>, string> code;
    cin >> t;
    while (t--) {
        cin >> c1 >> c2 >> name;
        pair <int, int> p(c1, c2);
        if(!code.count(p)) {
            code.insert(make_pair(p, name));
        }
        else {
            code[p] = name;
        }
    }

    cin >> test;
    while (test--) {
        cin >> c1 >> c2;
        pair <int, int> p(c1, c2);
        cout << code[p] << "\n";
    }
    return 0;
}