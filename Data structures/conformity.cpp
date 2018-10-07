#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

int main()
{
    int n;

    while (cin >> n, n) {
        map<string, int> popularity;
        int max_Frosh = -1, m;
        string s[5];

        for (int i = 0; i < n; ++i) {
            cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];
            sort (s, s+5);
            string sub_ids;
            for (int j = 0; j < 5; ++j) sub_ids += s[j];

            if (popularity.count(sub_ids)) {
                m = popularity[sub_ids] + 1;
                popularity[sub_ids] = m;
                max_Frosh = max(max_Frosh, m);
            }
            else {
                popularity[sub_ids] = 1;
                max_Frosh = max(max_Frosh, 1);
            }
        }

        int count = 0;
        map<string, int>::iterator it;
        for (it = popularity.begin(); it != popularity.end(); ++it)
            if (it->second == max_Frosh) count += max_Frosh;
        cout << count << "\n";
    }

    return 0;
}

