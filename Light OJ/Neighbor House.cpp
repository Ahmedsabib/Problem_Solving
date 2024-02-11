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
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i] >> b[i] >> c[i];
    }
    int dp[n + 1][3];
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = c[1];
    for (int i = 2; i <= n; ++i) {
      dp[i][0] = a[i] + min(dp[i - 1][1], dp[i - 1][2]);
      dp[i][1] = b[i] + min(dp[i - 1][0], dp[i - 1][2]);
      dp[i][2] = c[i] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
  }
  return 0;
}
