#include <bits/stdc++.h>

using namespace std;

int main ()
{
    string text;
    while (cin >> text) {
        list<char> res;
        list<char>::iterator it = res.begin();
        int len = text.length();

        for (int i = 0; i < len; i++) {
            if (text[i] == '[') {
                it = res.begin();
            }
            else if (text[i] == ']') {
                it = res.end();
            }
            else {
                res.insert(it, text[i]);
            }
        }

        for (it = res.begin(); it != res.end(); it++) {
            printf("%c", *it);
        }
        printf("\n");
    }

    return 0;
}
