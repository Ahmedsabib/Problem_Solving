#include <bits/stdc++.h>

using namespace std;

#define int long long

int lcm(int a, int b) { return a * b/__gcd(a, b); }

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 1; i < (1 << m); ++i) {
      int l = 1;
      for (int j = 0; j < m; ++j) {
        if (i & (1 << j)) l = lcm(l, a[j]);
      }
      if (__builtin_popcount(i)&1) ans += n/l;
      else ans -= n/l;
    }
    cout << n - ans << '\n';
  }
  return 0;
}
