#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool endmark;
    int counter, level;
    Node* next[3];
    Node() {
        endmark = false;
        counter = 0;
        for (int i = 0; i < 2; ++i)
            next[i] = NULL;
    }
};
Node *root;

int mxLen;

void Insert (char str[], int len) {
    Node *cur = root, *pre = NULL;
    for (int i = 0; i < len; ++i) {
        pre = cur;
        int id = str[i] - '0';
        if (cur->next[id] == NULL) {
            cur->next[id] = new Node();
        }
        cur = cur->next[id];
        ++cur->counter;
        cur->level = 1 + pre->level;
        mxLen = max(cur->counter * cur->level, mxLen);
    }
    cur->endmark = true;
}

int main() {
    //freopen("zzz.txt", "r", stdin);
    int t, n;
    scanf("%d", &t);
    char str[202];
    while (t--) {
        mxLen = 0;
        root = new Node();
        root->level = 0;
        scanf("%d", &n);
        while (n--) {
            scanf("%s", str);
            Insert(str, strlen(str));
        }
        printf("%d\n", mxLen);
    }

    return 0;
}
