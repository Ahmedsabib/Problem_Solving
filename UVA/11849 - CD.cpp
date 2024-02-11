#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int N, M;

    while (scanf("%d %d", &N, &M)) {
        if (N == 0 && M == 0)
            break;

        set<int> S;

        for (int i = 0; i < N; ++i) {
            int x;
            scanf("%d", &x);
            S.insert(x);
        }

        for (int i = 0; i < M; ++i) {
            int x;
            scanf("%d", &x);
            S.insert(x);
        }

        cout << (N + M) - (int)S.size() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
