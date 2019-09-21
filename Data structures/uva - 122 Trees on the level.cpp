#include <bits/stdc++.h>
using namespace std;
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {printf("%d ", i);} printf("\n");
#define what_is(x) cerr << #x << " = " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
/*---------------------------Codes-----------------------------*/

struct Node {
    int val;
    Node* left;
    Node* right;
    Node () {
        val = -1;
        left = NULL;
        right = NULL;
    }
};

Node* root;
string path;
bool complete;
int input_nodes, created_nodes;
vector<int> ans;

void FreeMemory(Node* root) {
    if (root == NULL) return;
    FreeMemory(root->left);
    FreeMemory(root->right);
    delete root;
}

void init() {
    FreeMemory(root);
    root = new Node();
    complete = true;
    ans.clear();
}

void insert(Node* root, int value, int pos) {
    if(pos == path.size()) {
        if (root->val != -1) complete = false;
        root->val = value;
    }
    else if (path[pos] == 'L') {
        if (root->left == NULL){
            root->left = new Node();
        }
        insert(root->left, value, pos + 1);
    }
    else {
        if (root->right == NULL) {
            root->right = new Node();
        }
        insert(root->right, value, pos + 1);
    }
}

bool bfs() {
    queue<Node*> q;
    q.push(root);
    Node* node;

    while(!q.empty()) {
        node = q.front(); q.pop();
        if (node->val == -1) return false;
        ans.emplace_back(node->val);
        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
    }

    return true;
}

void solve() {
    if (complete && bfs()) {
        int len = ans.size();
        for (int i = 0; i < len-1; ++i)
            printf("%d ", ans[i]);
        printf("%d\n", ans[len-1]);
    }
    else printf("not complete\n");
}

int main() {
    //FI;
    string s;
    int value;

    init();
    while (cin >> s) {
        if (s == "()") {
            solve();
            init();
        }
        else {
            int coma = find(s.begin(), s.end(), ',') - s.begin();
            s[0] = s[s.size() - 1] = s[coma] = ' ';
            stringstream sso(s);
            sso >> value;
            path = "";
            sso >> path;
            insert(root, value, 0);
        }
    }

    return 0;
}
