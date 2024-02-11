#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int k, m;

    while (cin >> k && k != 0) {
        cin >> m;
        set<int> S;

        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            S.insert(x);
        }

        int d = m, tot = m;

        while (m--) {
            int x, minimum, cnt = 0;
            cin >> x >> minimum;
            
            for (int i = 0; i < x; ++i) {
                int a;
                cin >> a;

                if (S.count(a))
                    ++cnt;
            }

            if (cnt < minimum)
                --d;
        }

        if (d == tot)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
