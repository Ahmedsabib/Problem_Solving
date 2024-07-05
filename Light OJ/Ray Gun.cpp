#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e6 + 5;

int f[maxn + 5], mark[maxn + 5];

void precompute() {
  for (int i = 2; i <= maxn; ++i) {
    if (!f[i]) {
      for (int k = i; k <= maxn; k += i) f[k]++;
    }
  }
  for (int i = 2; i <= 1000; ++i) {
    for (int k = i * i; k <= maxn; k += i * i) mark[k] = 1;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  precompute();

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int n, m;
    cin >> n >> m;
    if (n < m) swap(n, m);
    if (m == 0) {
      if (n > 0) cout << 1 << '\n';
      else cout << 0 << '\n';
      continue;
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      if (!mark[i]) {
        if (f[i]&1) ans -= (n/i) * (m/i);
        else ans += (n/i) * (m/i);
      }
    }
    cout << ans + 2 << '\n';
  }
  return 0;
}
