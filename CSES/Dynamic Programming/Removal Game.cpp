#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int sum = accumulate(a.begin(), a.end(), 0LL);
  vector<vector<int>> dp(n, vector<int> (n, 0));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      if (i == j) dp[i][j] = a[i];
      else {
        dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
      }
    }
  }
  cout << (sum + dp[0][n - 1])/2 << '\n';
  return 0;
}
