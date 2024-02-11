#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ":\n";
    int q;
    cin >> q;
    int ans = 0;
    while (q--) {
      string s;
      cin >> s;
      if (s == "donate") {
        int x;
        cin >> x;
        ans += x;
      }
      else {
        cout << ans << '\n';
      }
    }
  }
  return 0;
}
