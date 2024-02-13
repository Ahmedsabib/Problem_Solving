Rectangle Cutting#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int h, w;
  cin >> h >> w;
  vector<vector<int>> dp(h + 1, vector<int> (w + 1, inf));
  for (int i = 0; i <= h; ++i) {
    for (int j = 0; j <= w; ++j) {
      if (i == j) dp[i][j] = 0;
      else {
        for (int k = 1; k < i; ++k) {
          dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
        }
        for (int k = 1; k < j; ++k) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
        }
      }
    }
  }
  cout << dp[h][w] << '\n';
  return 0;
}
