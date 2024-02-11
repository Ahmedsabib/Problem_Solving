#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 55;

int dp[55][55][55];

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    string s, t, u;
    cin >> s >> t >> u;
    memset(dp, 0, sizeof(dp));
    int n = (int)s.size(), m = (int)t.size(), p = (int)u.size();
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        for (int k = 1; k <= p; ++k) {
          if (s[i - 1] == t[j - 1] && t[j - 1] == u[k - 1]) {
            dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
          }
          else {
            dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
          }
        }
      }
    }
    cout << dp[n][m][p] << '\n';
  }
  return 0;
}
