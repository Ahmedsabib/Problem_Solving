#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int N, K;

    while (cin >> N >> K && N) {
        int cnt = 0, prev;
        cin >> prev;
        cnt += (N - prev);

        for (int i = 1; i < K; ++i) {
            int x;
            cin >> x;

            if (x < prev)
                cnt += prev - x;

            prev = x;
        }

        cout << cnt << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
