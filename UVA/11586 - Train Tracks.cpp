#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int N;
    cin >> N;
    cin.ignore();
    
    string S;

    while (N--) {
        getline(cin, S);

        int cnt = 0;

        for (auto& x: S) {
            if (x == 'M')
                ++cnt;
            else if (x == 'F')
                --cnt;
        }

        if (cnt == 0 && (int)S.size() > 3)
            cout << "LOOP" << '\n';
        else
            cout << "NO LOOP" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
