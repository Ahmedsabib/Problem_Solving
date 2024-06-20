#include <bits/stdc++.h>

using namespace std;

#define int long long

int lcm(int a, int b) { return (a * b)/__gcd(a, b); }

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) cin >> a[i];
  int ans = 0;
  for (int i = 1; i < (1 << m); ++i) {
    int cnt = 0, p = 1;
    for (int j = 0; j < m; ++j) {
      if (i & (1 << j)) {
        p = lcm(p, a[j]);
        ++cnt;
      }
    }
    if (cnt&1) ans += n/p;
    else ans -= n/p;
  }
  cout << n - ans << '\n';
  return 0;
}
