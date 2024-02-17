#include <bits/stdc++.h>

using namespace std;

#define int long long

using pii = pair<int, string>;
using vpi = vector<pii>;

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    string s, t;
    cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    vector<vpi> dp(n + 1, vpi (m + 1, {0, ""}));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j].first = dp[i - 1][j - 1].first + 1;
          dp[i][j].second = dp[i - 1][j - 1].second + s[i - 1];
        }
        else if (dp[i - 1][j].first > dp[i][j - 1].first) dp[i][j] = dp[i - 1][j];
        else if (dp[i - 1][j].first < dp[i][j - 1].first) dp[i][j] = dp[i][j - 1];
        else {
          if (dp[i - 1][j].second > dp[i][j - 1].second) dp[i][j] = dp[i][j - 1];
          else dp[i][j] = dp[i - 1][j];
        }
      }
    }
    if (dp[n][m].first == 0) cout << ":(\n";
    else cout << dp[n][m].second << '\n';
  }
  return 0;
}
