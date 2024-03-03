#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 17;

int n, x[maxn], y[maxn], dp[1 << maxn];
int g[maxn][maxn];

int on_same_line(int a, int b, int c) {
  int x1 = x[a] * y[b] + x[b] * y[c] + x[c] * y[a];
  int y1 = x[b] * y[a] + x[c] * y[b] + x[a] * y[c];
  return x1 == y1;
}

int bitmask_dp(int mask) {
  if (mask == (1 << n) - 1) return 0;
  int &ret = dp[mask];
  if (~ret) return ret;
  ret = 10;
  int cnt = __builtin_popcount(mask);
  if (cnt == n - 1 || cnt == n - 2) return dp[mask] = 1;
  for (int i = 0; i < n; ++i) {
    if ((mask & (1 << i))) continue;
    for (int j = i + 1; j < n; ++j) {
      if ((mask & (1 << j))) continue;
      ret = min(ret, 1 + bitmask_dp((mask | g[i][j])));
    }
    break;
  }
  return ret;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int res = 0;
        res = (res | (1 << i));
        res = (res | (1 << j));
        for (int k = 0; k < n; ++k) {
          if (on_same_line(i, j, k)) res = (res | (1 << k));
        }
        g[i][j] = res;
      }
    }
    memset(dp, -1, sizeof(dp));
    cout << bitmask_dp(0) << '\n';
  }
  return 0;
}
