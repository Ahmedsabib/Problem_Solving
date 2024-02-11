#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
  if (a[0] == 0) for (int i = 0; i <= m; ++i) dp[0][i] = 1;
  else dp[0][a[0]] = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] == 0) {
      for (int j = 1; j <= m; ++j) {
        for (auto& x: {j - 1, j, j + 1}) {
          if (x >= 1 && x <= m) dp[i][j] = (dp[i][j] + dp[i - 1][x])%mod;
        }
      }
    }
    else {
      for (auto& x: {a[i] - 1, a[i], a[i] + 1}) {
        if (x >= 1 && x <= m) dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][x])%mod;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i) ans = (ans + dp[n - 1][i])%mod;
  cout << ans << '\n';
  return 0;
}
