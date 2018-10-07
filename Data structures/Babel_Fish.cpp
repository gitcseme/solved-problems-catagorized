#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

#define MP make_pair
typedef map<string, string> mss;

int main()
{   ios::sync_with_stdio(0); cin.tie(0);

    string english, foreign, temp;
    mss dictionary;
    getline(cin, temp);

    while (temp != "") {
        stringstream ss(temp);
        ss >> english >> foreign;
        dictionary.insert(MP(foreign, english));

        getline(cin, temp);
    }

    while (cin >> foreign) {
        if(dictionary[foreign] != "") {
            cout << dictionary[foreign] << "\n";
        }
        else cout << "eh\n";
    }

    return 0;
}
