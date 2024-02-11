#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int N;
    vector<int> A(1000);
    stack<int> S;

    while (cin >> N) {
        if (N == 0) 
            break;

        while (cin >> A[0]) {
            if (A[0] == 0)
                break;

            while (!S.empty())
                S.pop();

            int cur = 1;
            bool ok = true;

            for (int i = 1; i < N; ++i)
                cin >> A[i];

            for (int i = 0; i < N; ++i) {
                if (A[i] == cur) {
                    ++cur;
                    continue;
                }
                else if (A[i] < cur) {
                    if (!S.empty()) {
                        if (S.top() == A[i]) {
                            S.pop();
                            continue;
                        }
                    }

                    ok = false;
                    break;
                }
                else if (A[i] > cur) {
                    while (A[i] != cur) {
                        S.push(cur);
                        ++cur;
                    }

                    ++cur;
                    continue;
                }
            }

            cout << (ok? "Yes":"No") << '\n';
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
