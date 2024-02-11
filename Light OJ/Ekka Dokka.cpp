#include <bits/stdc++.h>
using namespace std;

void run_case(int test_case) {
    cout << "Case " << test_case << ": ";

    int64_t N;
    cin >> N;
    int64_t a = 0, b = 0;

    if (N%2 == 0) {
        int64_t X = N/2, cnt = 2;

        while (X%2 == 0) {
            cnt *= 2;
            X /= 2;
        }

        a = X;
        b = cnt;

        cout << a << ' ' << b << '\n';
    }
    else {
        cout << "Impossible" << '\n';
    }
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
