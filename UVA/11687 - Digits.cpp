#include <bits/stdc++.h>
using namespace std;
#define getDigits(x) to_string(x).size()

const int INF = (int) 1e9 + 7;

void run_case() {
    string S;

    while (cin >> S && S != "END") {
        int cnt = 0, a = 0, b = 0;
        a = (((int)S.size() <= 3)? stoi(S) : 0);
        b = (int)S.size();
        cnt = 1;

        while(a != b) {
            ++cnt;
            a = b;
            b = getDigits(b);
        }

        cout << cnt << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
