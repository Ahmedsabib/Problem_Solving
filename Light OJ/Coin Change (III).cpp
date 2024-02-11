#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 105;
const int maxm = 1e5 + 5;

int n, m;
int a[maxm], b[10 * maxn];
int dp[maxm], used[maxm];

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int j = 1; j <= n; ++j) cin >> b[j];
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      memset(used, 0, sizeof(used));
      for (int j = a[i]; j <= m; ++j) {
        if (!dp[j] && dp[j - a[i]] && used[j - a[i]] < b[i]) {
          ++ans;
          used[j] = used[j - a[i]] + 1;
          dp[j] = 1;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
