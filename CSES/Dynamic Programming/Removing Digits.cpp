#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  int ans = 0;
  while (n != 0) {
    int m = n, maxi = 0;
    while (m) {
      int res = m%10;
      maxi = max(maxi, res);
      m /= 10;
    }
    n -= maxi;
    ++ans;
  }
  cout << ans << '\n';
  return 0;
}
