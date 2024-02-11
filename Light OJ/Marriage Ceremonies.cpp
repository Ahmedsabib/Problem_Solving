#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, a[16][16];
int dp[16][1 << 16];

int bitmask_dp(int pos, int mask) {
  if (mask == (1 << n) - 1) return 0;
  if (dp[pos][mask] != -1) return dp[pos][mask];
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if ((1 << i) & mask) continue;
    ans = max(ans, a[pos][i] + bitmask_dp(pos + 1, (1 << i) | mask));
  }
  dp[pos][mask] = ans;
  return dp[pos][mask];
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    }
    memset(dp, -1, sizeof(dp));
    cout << bitmask_dp(0, 0) << '\n';
  }
  return 0;
}
