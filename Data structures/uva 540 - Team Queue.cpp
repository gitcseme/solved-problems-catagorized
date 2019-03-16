#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

int team[1000000];


int main() {
    FI;

    int t, scenario = 0, N, player;
    string command;

    while (cin >> t, t)
    {
        queue <int> q[1005];
        queue <int> teamQ;

        for (int i = 1; i <= t; ++i) {
            cin >> N;
            while (N--) {
                cin >> player;
                team[player] = i;
            }
        }

        printf("Scenario #%d\n", ++scenario);
        while (true) {
            cin >> command;
            if (command == "STOP") break;
            else if (command == "ENQUEUE") {
                cin >> player;
                if (q[team[player]].empty()) {
                    teamQ.push(team[player]);
                }
                q[team[player]].push(player);
            }
            else {
                int frontTeam = teamQ.front();
                if (q[frontTeam].empty()){
                    teamQ.pop();
                    frontTeam = teamQ.front();
                }

                printf("%d\n", q[frontTeam].front());
                q[frontTeam].pop();
            }
        }
        puts("");
    }


    return 0;
}

