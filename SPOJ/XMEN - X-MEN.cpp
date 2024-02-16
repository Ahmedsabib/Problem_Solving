#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5 + 5;
const int inf = 1e9 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<int> ind(n + 1), dp(n + 1, inf);
    dp[0] = -inf;
    for (int i = 0; i < n; ++i) ind[a[i]] = i + 1; 
    for (int i = 0; i < n; ++i) b[i] = ind[b[i]];
    for (int i = 0; i < n; ++i) {
      int pos = upper_bound(dp.begin(), dp.end(), b[i]) - dp.begin();
      if (dp[pos - 1] < b[i] && b[i] < dp[pos]) dp[pos] = b[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
      if (dp[i] < inf) ans = i;
    }
    cout << ans << '\n';
  }
  return 0;
}
