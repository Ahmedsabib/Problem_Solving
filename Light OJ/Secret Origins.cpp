#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(int n) {
    string res = "";
    
    for (int i = 31; i >= 0; i--) {
        int k = 1 << i;
        res += (n & k)? '1' : '0';
    }

    return res;
}

void run_case(int test_case) {
    int64_t N;
    cin >> N;

    string S = decimalToBinary(N);
    next_permutation(S.begin(), S.end());
    int64_t ans = stoi(S, 0, 2); //converts the string in to a decimal integer

    cout << "Case " << test_case << ": " << ans << '\n';
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
