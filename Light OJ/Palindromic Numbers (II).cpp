#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    string S;
    cin >> S;
    string T = S;
    reverse(S.begin(), S.end());
    cout << (S == T? "Yes\n" : "No\n");
  }
  return 0;
}
