#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int sum = 0, ans = 0;
    for (int i = 0; i < min(p, n); ++i) {
      if (sum + a[i] > q) {
        break;
      }
      sum += a[i];
      ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}
