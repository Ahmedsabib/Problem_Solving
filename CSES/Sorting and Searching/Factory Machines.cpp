#include <bits/stdc++.h>
using namespace std;

const int INF = (int) 1e18;

int64_t N, T;
vector<int64_t> A;

bool check(int64_t x) {
    int64_t products = 0;

    for (int i = 0; i < N; ++i)
        products += (x/A[i]);

    return products >= T;
}

void run_case() {
    cin >> N >> T;
    A.resize(N);

    for (auto& x: A)
        cin >> x;

    int64_t low = 0, high = 1;

    while (!check(high))
        high *= 2;

    while (low <= high) {
        int64_t mid = (low + high)/2;

        if (check(mid))
            high = mid - 1;
        else
            low = mid + 1;
    }

    cout << high + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
