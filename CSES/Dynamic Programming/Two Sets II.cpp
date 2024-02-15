#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  int tot = (n * (n + 1))/2;
  if (tot%2 != 0) {
    cout << 0 << '\n';
    return 0;
  }
  int target = tot/2;
  vector<vector<int>> dp(n, vector<int> (target + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= target; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - i >= 0) dp[i][j] += dp[i - 1][j - i];
      dp[i][j] %= mod;
    }
  }
  cout << dp[n - 1][target] << '\n';
  return 0;
}
