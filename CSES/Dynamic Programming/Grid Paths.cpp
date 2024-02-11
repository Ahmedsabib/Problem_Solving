#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) cin >> grid[i];
  vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
  if (grid[0][0] == '.') dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 && j == 0) continue;
      if (grid[i][j] == '*') continue;
      if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
      if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
      dp[i][j] %= mod;
    }
  }
  cout << dp[n - 1][n - 1] << '\n';
  return 0;
}
