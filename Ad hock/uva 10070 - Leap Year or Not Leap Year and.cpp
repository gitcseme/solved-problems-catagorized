#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int main() {
    FI;

    string year;
    int rem4, rem100, rem15, rem55, rem400, len;
    bool newLine = false, ordinary, leapYear;

    while (getline(cin, year)) {
        if (newLine) cout << "\n";
        newLine = true;

        rem4 = rem100 = rem15 = rem55 = rem400 = 0;
        leapYear = false;
        ordinary = true;
        len = year.size();

        for (int i = 0; i < len; ++i)
        {
            rem4 = (rem4 * 10 + year[i] - '0') % 4;
            rem100 = (rem100 * 10 + year[i] - '0') % 100;
            rem15 = (rem15 * 10 + year[i] - '0') % 15;
            rem55 = (rem55 * 10 + year[i] - '0') % 55;
            rem400 = (rem400 * 10 + year[i] - '0') % 400;
        }

        if ((rem4==0 && rem100!=0) || rem400==0) {
            leapYear = true;
            ordinary = false;
            cout << "This is leap year.\n";
        }
        if (rem15 == 0) {
            ordinary = false;
            cout << "This is huluculu festival year.\n";
        }
        if (leapYear && rem55 == 0) {
            cout << "This is bulukulu festival year.\n";
        }
        if (ordinary)
            cout << "This is an ordinary year.\n";
    }

    return 0;
}
