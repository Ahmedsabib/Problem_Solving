#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A;

int check(int x) {
    int res = 0, cnt = 1;

    for (int i = 0; i < N; ++i) {
        if (A[i] > x) return INT_MAX;

        if (res + A[i] <= x) {
            res += A[i];
        }
        else {
            res = A[i];
            ++cnt;
        }

    }

    return cnt;
}

//Time Complexity O(log n)
int binary_search() {
    int low = 0, high = 1000000000, mid;

    for (int i = 0; i < 100; ++i) {
        mid = (low + high)/2;

        if (check(mid) <= M)
            high = mid;
        else
            low = mid + 1;
    }

    return mid;
}

void run_case(int test_case) {
    cin >> N >> M;
    A.resize(N);

    for (auto& x: A)
        cin >> x;

    cout << "Case " << test_case << ": " << binary_search() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests;
    cin >> tests;

    for (int tc = 1; tc <= tests; tc++) {
        run_case(tc);
        cout << flush;
    }

    return 0;
}
