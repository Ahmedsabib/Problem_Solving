#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int64_t N, M;
    cin >> N >> M;
    vector<int> B;
    vector<pair<int, int>> A;

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        B.push_back(x);
        A.push_back({x, i + 1});
    }

    sort(A.begin(), A.end());

    // Two Pointers Technique for 3SUM Problem
    // Time Complexity O(N^2)
    for (int i = 0; i < N; ++i) {
        int low = 0, high = N - 1;

        while (low < high) {
            if (A[low].second == i + 1) {
                low++;
            }
            else if (A[high].second == i + 1) {
                --high;
            }
            else if (B[i] + A[low].first + A[high].first > M) {
                --high;
            }
            else if (B[i] + A[low].first + A[high].first < M) {
                ++low;
            }
            else {
                cout << i + 1 << ' ' << A[low].second << ' ' << A[high].second << '\n';
                return;
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
