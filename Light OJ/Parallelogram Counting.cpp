#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int x = a[i] + a[j];
        int y = b[i] + b[j];
        p.push_back({x, y});
      }
    }
    sort(p.begin(), p.end());
    int ans = 0, cnt = 0;
    for (int i = 1; i < (int)p.size(); ++i) {
      if (p[i].first == p[i - 1].first && p[i].second == p[i - 1].second) ++cnt;
      else {
        ans += (cnt * (cnt + 1))/2;
        cnt = 0;
      }
    }
    if (cnt > 0) ans += (cnt * (cnt - 1))/2;
    cout << ans << '\n';
  }
  return 0;
}
