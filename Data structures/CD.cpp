#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N, M, num;

    while (cin>>N>>M, N,M) {
        set<int> cd_set;
        for (int i = 0; i <N ; ++i) {
            cin >> num;
            cd_set.insert(num);
        }
        int count = 0;
        for (int j = 0; j < M; ++j) {
            cin >> num;
            if (cd_set.count(num)) ++count;
        }
        cout << count << "\n";
    }

    return 0;
}

