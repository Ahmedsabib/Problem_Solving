#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int n, m, c;
    int t = 1;
    
    while (cin >> n >> m >> c) {
        if (n == 0  && m == 0 && c == 0)
            break;

        vector<int> A(n);

        for (auto& x: A)
            cin >> x;

        int sum = 0, maximum = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            --x;

            if (!vis[x]) {
                sum += A[x];
                vis[x] = true;
            }
            else {
                sum -= A[x];
                vis[x] = false;
            }

            maximum = max(maximum, sum);
        }

        cout << "Sequence " << t++ << '\n';

        if (maximum <= c) {
            cout << "Fuse was not blown." << '\n';
            cout << "Maximal power consumption was " << maximum << " amperes." << '\n';
        }
        else {
            cout << "Fuse was blown." << '\n';
        }

        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;
    
    while (tests-- > 0)
        run_case();

    return 0;
}
