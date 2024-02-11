#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int64_t N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cout << i << ' ';
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
