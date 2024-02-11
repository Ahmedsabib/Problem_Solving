#include <bits/stdc++.h>
using namespace std;

string s = "";

void run_case() {
    cout << s;
    s = '\n';

    int M, N;
    cin >> M >> N;
    vector<int> A(M), B(N);

    for (auto& x: A)
        cin >> x;

    for (auto& x: B)
        cin >> x;

    multiset<int> S;
    S.insert(A[0]);

    int cnt = 0;
    auto it = S.begin();

    for (int num = 1; num < M; ++num) {
        while (cnt < N && B[cnt] == num) {
            ++cnt;
            cout << *it << '\n';
            ++it;
        }

        S.insert(A[num]);

        if (it == S.end() || A[num] < *it)
            --it;
    }

    while (cnt < N && B[cnt] == M) {
        ++cnt;
        cout << *it << '\n';
        ++it;
    }

}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();

    return 0;
}
