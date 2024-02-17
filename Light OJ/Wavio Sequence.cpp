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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp1, dp2, pref, suf;
    for (int i = 0; i < n; ++i) {
      int ind = lower_bound(dp1.begin(), dp1.end(), a[i]) - dp1.begin();
      if (ind == (int)dp1.size()) dp1.push_back(a[i]);
      else dp1[ind] = a[i];
      pref.push_back((int)dp1.size());
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
      int ind = lower_bound(dp2.begin(), dp2.end(), a[i]) - dp2.begin();
      if (ind == (int)dp2.size()) dp2.push_back(a[i]);
      else dp2[ind] = a[i];
      suf.push_back((int)dp2.size());
    }
    reverse(suf.begin(), suf.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int val = min(pref[i], suf[i]);
      ans = max(ans, val * 2 - 1);
    }
    cout << ans << '\n';
  }
  return 0;
}
