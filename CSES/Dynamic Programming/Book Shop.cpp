#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1e3 + 5;
const int maxm = 1e5 + 5;
 
int n, x, pages[maxn], prices[maxm];
int dp[maxn][maxm];
 
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) cin >> prices[i];
  for (int i = 1; i <= n; ++i) cin >> pages[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= x; ++j) {
      if (j - prices[i] >= 0) {
        dp[i][j] = max(pages[i] + dp[i - 1][j - prices[i]], dp[i - 1][j]);
      }
      else dp[i][j] = dp[i - 1][j];
    }
  }
  cout << dp[n][x] << '\n';
  return 0;
}
