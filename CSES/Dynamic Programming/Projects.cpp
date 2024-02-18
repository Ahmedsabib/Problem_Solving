#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    b[i]++;
    mp[a[i]];
    mp[b[i]];
  }
  int d = 0;
  for (auto& x: mp) {
    x.second = d++;
  }
  vector<vector<pair<int, int>>> p(d);
  for (int i = 0; i < n; ++i) {
    p[mp[b[i]]].push_back({mp[a[i]], c[i]});
  }
  vector<int> dp(d, 0);
  for (int i = 0; i < d; ++i) {
    if (i > 0) dp[i] = dp[i - 1];
    for (auto& x: p[i]) {
      dp[i] = max(dp[i], dp[x.first] + x.second);
    }
  }
  cout << dp[d - 1] << '\n';
  return 0;
}
