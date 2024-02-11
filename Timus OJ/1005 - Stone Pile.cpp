#include <bits/stdc++.h>
using namespace std;

const int INF = (int) 1e9 + 7;

void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (auto& x: A)
        cin >> x;

    int64_t sum = accumulate(A.begin(), A.end(), 0LL);
    int64_t ans = INF;

    for (int i = 0; i < (1 << N); ++i) {
        int64_t c = 0;

        for (int j = 0; j < N; ++j) {
            if (i & (1 << j))
                c += A[j];
        }

        ans = min(ans, abs(sum - 2 * c));
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
