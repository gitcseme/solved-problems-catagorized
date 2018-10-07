#include <bits/stdc++.h>
using namespace std;

bool flag;
struct Node {
    bool endmark;
    Node* next[10 + 1];
    Node() {
        endmark = false;
        for (int i = 0; i < 10; ++i)
            next[i] = NULL;
    }
};
Node *root;

void Insert (char str[], int len) {
    Node *cur = root;
    for (int i = 0; i < len; ++i) {
        int id = str[i] - '0';
        if (cur->next[id] == NULL) {
            if (cur->endmark) flag = false; // already a word ends here.
            cur->next[id] = new Node();
        }
        cur = cur->next[id];
    }
    cur->endmark = true;

    for (int i = 0; i < 10; ++i)
        if (cur->next[i])
            flag = false; // it's a prefix of another word.
}

void del (Node *cur) {
    for (int i = 0; i < 10; ++i)
        if (cur->next[i])
            del(cur->next[i]);
    delete(cur);
}

int main() {
    int t, n;
    scanf("%d", &t);
    char str[20];
    while (t--) {
        flag = true;
        scanf("%d", &n);
        root = new Node();
        while (n--) {
            scanf("%s", str);
            Insert(str, strlen(str));
        }
        if (flag) puts("YES");
        else puts("NO");

        del(root);
    }

    return 0;
}
