#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
int match;
bool qm, pqm, stkm, local;
bool match_with(vector<int>& out, vector<int>& with);

int main() { ios::sync_with_stdio(0); cin.tie(0);
    int  n, com, e, input, output;

    while (cin >> n) {
        queue<int> q;
        stack<int> stk;
        priority_queue<int> pq;
        match = 0; qm = pqm = stkm = false; local = true; input = output = 0;
        vector<int> out;
        vector<int> qout;
        vector<int> pqout;
        vector<int> stkout;

        for (int i = 0; i < n; i++) {
            cin >> com >> e;
            if (com == 1 && local) {
                ++input;
                q.push(e);
                pq.push(e);
                stk.push(e);
            }
            else {
                ++output;
                if (output > input) {
                    local = false;
                }
                if (local) {
                    out.push_back(e);
                    qout.push_back(q.front());   q.pop();
                    pqout.push_back(pq.top());   pq.pop();
                    stkout.push_back(stk.top()); stk.pop();
                }
            }
        }
        if (!local) {
            cout << "impossible\n";
            continue;
        }
        qm = match_with(out, qout);
        pqm = match_with(out, pqout);
        stkm = match_with(out, stkout);

        if (match == 0) cout << "impossible\n";
        else if(match == 1) {
            if(qm) cout << "queue\n";
            else if(pqm) cout << "priority queue\n";
            else cout << "stack\n";
        }
        else cout << "not sure\n";
    }

    return 0;
}

bool match_with(vector<int>& out, vector<int>& with) {
    int len = out.size();
    for (int i = 0; i < len; ++i) {
        if(out[i] != with[i]) return false;
    }
    ++match;
    return true;
}
