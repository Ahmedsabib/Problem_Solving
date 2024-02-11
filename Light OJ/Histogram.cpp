#include <bits/stdc++.h>
using namespace std;

void run_case(int test_case) {
    int N;
    cin >> N;
    vector<int> A(N);

    for (auto& x: A)
        cin >> x;

    stack<int> store;

    int ans = 0, cnt = 0, top = 0, i = 0;

    while (i < N) {
        if (store.empty() || A[store.top()] <= A[i]) {
            store.push(i++);
        }
        else {
            top = store.top();
            store.pop();
            cnt = A[top] * (store.empty()? i : i - store.top() - 1);
            ans = max(ans, cnt);
        }
    }

    while (!store.empty()) {
        top = store.top();
        store.pop();
        cnt = A[top] * (store.empty()? i : i - store.top() - 1);
        ans = max(ans, cnt);
    }

    cout << "Case " << test_case << ": " << ans << '\n';
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
