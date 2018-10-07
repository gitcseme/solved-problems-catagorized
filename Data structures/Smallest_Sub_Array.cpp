#include <iostream>
#include <set>
#include <deque>
#include <cstring>
using namespace std;

int main() {   ios::sync_with_stdio(0); cin.tie(0);

    int T, N, M, K, min_sub_arr, sz, distinct;
    cin >> T;

    for (int cse = 1; cse <= T; ++cse) {
        cin >> N >> M >> K;
        int arr[N + 5];
        min_sub_arr = N + 5;
        arr[1]=1;
        arr[2]=2;
        arr[3]=3;
        for (int i = 4; i <= N; ++i) arr[i] = ((arr[i-1] + arr[i-2] + arr[i-3]) % M) + 1;

        deque<int> dq;
        int dist[K+1];
        distinct = 0;
        memset(dist, 0, sizeof(dist));

        for (int i = 1; i <= N; ++i) {
            if(arr[i] <= K) {
                if(dist[arr[i]] == 0)
                    ++distinct;
                ++dist[arr[i]];
            }
            dq.push_back(arr[i]);

            while(!dq.empty() && distinct == K) {
                sz = dq.size();
                min_sub_arr = min (min_sub_arr, sz);

                int frnt = dq.front();
                dq.pop_front();
                if (frnt <= K && dist[frnt] < 2)
                    --distinct;
                --dist[frnt];
            }
        }

        if (min_sub_arr > N) cout << "Case "<<cse<<": " << "sequence nai";
        else cout << "Case "<<cse<<": " << min_sub_arr;
        cout << "\n";
    }

    return 0;
}
