#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n, num, a, b;
    long long cost;

    while (cin >> n, n) {
        cost = 0;
        priority_queue<int, vector<int>, greater<int> > pq;

        for (int i = 0; i < n; i++) {
            cin >> num;
            pq.push(num);
        }

        while (pq.size() > 1) {
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();

            cost += (a+b);
            pq.push((a+b));
        }

        cout << cost << "\n";
    }
    return 0;
}
