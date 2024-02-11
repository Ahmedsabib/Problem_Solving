#include <bits/stdc++.h>
using namespace std;

vector<int64_t> fact(20);

//Storing all the factorials from 1 to 20 in a vector
void precalculation() {
    int64_t d = 1;

    fact[0] = 1;

    for (int64_t i = 1; i <= 20; ++i) {
        fact[i] = i * d;
        d = fact[i];
    }
}

void run_case(int test_case) {
    precalculation(); //function calling

    int64_t N;
    cin >> N;
    vector<int> ans;//vector for storing answer

    for (int i = 20; i >= 0; --i) {
        if (fact[i] <= N) {
            N -= fact[i];
            ans.push_back(i);
        }
    }

    cout << "Case " << test_case << ": ";

    if (N == 0) {
        for (int i = (int)ans.size() - 1; i >= 1; --i)
            cout << ans[i] << "!+";

        cout << ans[0] << '!' << '\n';
    }
    else {
        cout << "impossible" << '\n';
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
