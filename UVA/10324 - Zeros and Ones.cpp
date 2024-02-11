#include <bits/stdc++.h>
using namespace std;

void run_case() {
    string S;
    int t = 0;

    while (cin >> S) {
        ++t;

        int len = (int)S.size();
        vector<int> freq(len);

        for (int i = 1; i < len; ++i) {
            if (S[i] != S[i-1])
                freq[i] = freq[i-1] + 1;
            else
                freq[i] = freq[i-1];
        }

        cout << "Case " << t << ":" << '\n';

        int N;
        cin >> N;

        while (N--) {
            int a, b;
            cin >> a >> b;

            if (freq[a] == freq[b])
                cout << "Yes" << '\n';
            else
                cout << "No" << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
