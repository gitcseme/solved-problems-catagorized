#include <bits/stdc++.h>
using namespace std;

vector <char> suffix;
char prefix[30];
int preLen;
bool init;
char alphabet[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

struct Node {
    bool endmark;
    Node* next[26 + 1];
    Node() {
        endmark = false;
        for (int i = 0; i < 26; ++i)
            next[i] = NULL;
    }
};
Node *root;

void Insert (char str[], int len) {
    Node *cur = root;
    for (int i = 0; i < len; ++i) {
        int id = str[i] - 'a';
        if (cur->next[id] == NULL) {
            cur->next[id] = new Node();
        }
        cur = cur->next[id];
    }
    cur->endmark = true;
}

void prntIt () {
    printf("%s", prefix);
    for (int i = 0; i < suffix.size(); ++i) printf("%c", suffix[i]);
    puts("");
}

void printRecur (Node* cur) {
    if (cur->endmark && init) {
        prntIt();
    }
    init = true;
    Node* dr = cur;
    for (int i = 0; i < 26; ++i) {
        if (dr->next[i]) {
            suffix.push_back(alphabet[i]);
            printRecur(dr->next[i]);
        }
    }
    suffix.pop_back();
}

bool get_pre() {
    Node* cur = root;
    for (int i = 0; i < preLen; ++i) {
        int id = prefix[i] - 'a';
        if (cur->next[id] == NULL)
            return false;
        cur = cur->next[id];
    }

    printRecur(cur);
    return true;
}

int main() {
    freopen("inp.txt", "r", stdin);

    root = new Node(); // giving root a physical memory.
    int N, k;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        char str[30];
        scanf("%s", str);
        Insert(str, strlen(str));
    }

    scanf("%d", &k);
    for (int caseno = 1; caseno <= k; ++caseno) {
        printf("Case #%d:\n", caseno);
        scanf("%s", prefix);
        preLen = strlen(prefix);
        suffix.clear();
        init = false;
        if (get_pre() == false) puts("No match.");
    }

    return 0;
}
