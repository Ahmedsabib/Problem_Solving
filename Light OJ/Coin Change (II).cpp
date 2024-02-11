#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 105;
const int maxm = 1e5 + 5;
const int mod = 100000007;

int n, k;
int coins[5 * maxn];
int dp[maxm];

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    memset(coins, 0, sizeof(coins));
    for (int i = 1; i <= n; ++i) cin >> coins[i];
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= k; ++j) {
        if (j >= coins[i]) {
          dp[j] += dp[j - coins[i]];
        }
        dp[j] %= mod;
      }
    }
    cout << dp[k] << '\n';
  }
  return 0;
}
