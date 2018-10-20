#include <bits/stdc++.h>
using namespace std;

#define N 10000000 + 25
int phi[N];
int cum[N];

void preCall() {
    phi[1] = 1;
    for(int i = 2; i < N; ++i) {
        if (!phi[i]) {
            for (int j = i; j < N; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = (phi[j]/i) * (i-1);
            }
        }
    }
}

bool pre (int a, int b) {
    int arr[10]; memset(arr, 0, sizeof(arr));
    while (a) ++arr[a%10], a /= 10;
    while (b) --arr[b%10], b /= 10;

    for (int i = 0; i < 10; ++i) if (arr[i] != 0) return false;
    return true;
}

int main () {
    preCall();
    int rep = -1, t, M;
    cum[1] = -1;
    for (int i = 2; i < N; ++i) {
        if(pre(i, phi[i])) {
            if (rep == -1) rep = i;
            else if (1LL * rep * phi[i] >= 1LL * i * phi[rep])
                rep = i;
        }
        cum[i] = rep;
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &M);
        if (cum[M-1] != -1)
            printf("%d\n", cum[M-1]);
        else
            printf("No solution.\n");
    }

    return 0;
}
