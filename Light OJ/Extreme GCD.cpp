#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e4 + 5;

int d[maxn], ans[maxn];

int ncr(int n, int k) {
  if (k > n) return 0;
  int res = 1;
  for (int i = n - k + 1; i <= n; ++i) res *= i;
  return res/24;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 <<  ": ";
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    memset(d, 0, sizeof(d));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j * j <= a[i]; ++j) {
        if (a[i]%j == 0) {
          d[j]++;
          if (j * j != a[i]) d[a[i]/j]++;
        }
      }
    }
    for (int i = maxn - 1; i >= 1; --i) {
      ans[i] = ncr(d[i], 4);
      for (int j = i + i; j < maxn; j += i) ans[i] -= ans[j];
    }
    cout << ans[1] << '\n';
  }
  return 0;
}
