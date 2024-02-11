#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      int x = abs(a[i]);
      if (mp.count(x)) {
        mp[x] = a[i];
      }
      mp[x] = a[i];
    }
    long long ans = 0;
    for (auto& x: mp) {
      ans += x.second;
    }
    cout << ans << '\n';
  }
  return 0;
}
