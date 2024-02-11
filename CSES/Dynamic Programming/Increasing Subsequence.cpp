#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e9 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> dp(n + 1, inf);
  dp[0] = -inf;
  for (int i = 0; i < n; ++i) {
    int ind = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    if (dp[ind - 1] < a[i] && a[i] < dp[ind]) dp[ind] = a[i];
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (dp[i] < inf) ans = i;
  }
  cout << ans << '\n';
  return 0;
}
