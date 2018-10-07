#include <iostream>

using namespace std;

int main()
{
    int N, S, l, r, min_len;
    bool flag;
    long long local_sum;
    while (cin >> N >> S) {
        int ara[N];
        flag = false;
        for (int i = 0; i < N; i++)
            cin >> ara[i];

        l = r = 0;
        min_len = 100000;
        local_sum = ara[0];
        while(r < N) {
            if (local_sum < S) {
                local_sum += ara[++r];
            }
            else {
                flag = true;
                min_len = min (min_len, (r-l+1));
                local_sum -= ara[l++];
            }
        }
        if(flag)
            cout << min_len << "\n";
        else
            cout << "0" << "\n";
    }
    return 0;
}
