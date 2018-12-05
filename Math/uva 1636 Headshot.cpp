#include <bits/stdc++.h>
using namespace std;

char ch[105];
int len, a, b, c, d;

void r() {
    int cnt = 0;
    for (int i = 0; i < len; ++i)
        if (ch[i] == '0') ++cnt;

    a = cnt;
    b = len;
}

void s() {
    int cnt = 0;
    for (int i = 1; i < len; ++i)
        if (ch[i] == '0' && ch[i-1] == '0') ++cnt;

    if (ch[0] == '0' && ch[len-1] == '0') ++cnt;
    c = cnt;
    d = a;
}

int main () {

    while (scanf("%s", ch) != EOF) {
        len = strlen(ch);
        r();
        s();
        if ( (a * d) > (b * c) ) printf("ROTATE\n");
        else if ( (a * d) < (b * c) ) printf("SHOOT\n");
        else printf("EQUAL\n");
    }

    return 0;
}
