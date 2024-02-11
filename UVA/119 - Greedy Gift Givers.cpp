#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int N;
    bool ok = false;

    while (cin >> N) {
        map<string, int> mp;
        vector<string> name;

        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            
            mp[s] = 0;
            name.push_back(s);
        }

        for (int i = 0; i < N; ++i) {
            string S;
            cin >> S;

            int R, T;
            cin >> R >> T;

            if (T == 0)
                continue;

            int gift = R/T;
            mp[S] -= gift * T;

            for (int j = 0; j < T; ++j) {
                string ss;
                cin >> ss;

                mp[ss] += gift;
            }
        }

        if (ok)
            cout << '\n';

        for (int i = 0; i < N; ++i)
            cout << name[i] << ' ' << mp[name[i]] << '\n';

        ok = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
