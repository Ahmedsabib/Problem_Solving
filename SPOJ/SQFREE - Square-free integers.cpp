#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e7 + 5;

int mobius[maxn];

void mobius_function() {
  mobius[1] = -1;
  for (int i = 1; i < maxn; ++i) {
    if (mobius[i]) {
      mobius[i] = -mobius[i];
      for (int j = 2 * i; j < maxn; j += i) mobius[j] += mobius[i];
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  mobius_function();

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; ++i) ans += mobius[i] * n/(i * i);
    cout << ans << '\n';
  }
  return 0;
}
