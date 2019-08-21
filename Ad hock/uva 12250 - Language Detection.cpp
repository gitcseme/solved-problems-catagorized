#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int main() {
    //FI;

    string greet;
    map<string, string> m;
    m["HELLO"] = "ENGLISH";
    m["HOLA"] = "SPANISH";
    m["HALLO"] = "GERMAN";
    m["BONJOUR"] = "FRENCH";
    m["CIAO"] = "ITALIAN";
    m["ZDRAVSTVUJTE"] = "RUSSIAN";

    int caseno = 1;
    while (cin >> greet) {
        if (greet == "#") break;
        if (m.count(greet))
            cout << "Case " << caseno << ": " << m[greet] << "\n";
        else
            cout << "Case " << caseno << ": " << "UNKNOWN" << "\n";

        ++caseno;
    }

    return 0;
}
