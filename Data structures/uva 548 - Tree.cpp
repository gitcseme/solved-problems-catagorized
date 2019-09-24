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
    Node *left, *right;
    Node(int v) {
        val = v;
        left = right = NULL;
    }
};

vector<int> inOrder;
vector<int> postOrder;
unordered_map<int, int> mp;
int postIndex;
int minCost, min_Leaf;

void freeMemory(Node* root) {
    if (root == NULL) return;
    freeMemory(root->left);
    freeMemory(root->right);
    delete (root);
}


void init() {
    inOrder.clear();
    postOrder.clear();
    mp.clear();
    minCost = INT_MAX;
    min_Leaf = INT_MAX;
}

vector<int> process(string s, bool f) {
    stringstream sso(s);
    int v;
    vector<int> ret;
    int i = 0;
    if (f) {
        while (sso >> v) {
            ret.emplace_back(v);
            mp[v] = i++;
        }
    }
    else {
        while (sso >> v) {
            ret.emplace_back(v);
        }
    }
    return ret;
}

Node* build_tree(int inStart, int inEnd) {
    if (inStart > inEnd)
        return NULL;

    int currRoot = postOrder[postIndex];
    --postIndex;
    Node* node = new Node(currRoot);

    if (inStart == inEnd) return node;

    int inRootIndex = mp[currRoot];
    node->right = build_tree(inRootIndex + 1, inEnd);
    node->left = build_tree(inStart, inRootIndex - 1);

    return node;
}

void dfs(Node* root, int costTil) {
    if (root->left == NULL && root->right == NULL) {
        if (minCost == costTil) min_Leaf = min(min_Leaf, root->val);
        else if (costTil < minCost) {
            minCost = costTil;
            min_Leaf = root->val;
        }
        return;
    }

    if (root->left != NULL)
        dfs(root->left, costTil + root->left->val);
    if (root->right != NULL)
        dfs(root->right, costTil + root->right->val);
}

void InorderTraversal(Node* root) {
    if (root == NULL) return;
    InorderTraversal(root->left);
    printf("%d ", root->val);
    InorderTraversal(root->right);
}

int main() {
    //FI;

    string s;
    while (getline(cin, s)) {
        init();
        inOrder = process(s, true);
        getline(cin, s);
        postOrder = process(s, false);

        int n = inOrder.size();
        postIndex = n-1;
        Node* root = build_tree(0, n-1);

        dfs(root, root->val);
        printf("%d\n", min_Leaf);

        freeMemory(root);
    }

    return 0;
}
