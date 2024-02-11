#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int64_t N, M;
    cin >> N >> M;
    vector<int> A(N);

    for (auto& x: A)
        cin >> x;

    map<int64_t, int64_t> mp;

    int64_t sum = 0, ans = 0;

    for (int i = 0; i < N; ++i) {
        sum += A[i];

        if (sum == M)
            ++ans;

        if (mp.find(sum - M) != mp.end())
            ans += mp[sum - M];

        mp[sum]++;
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
