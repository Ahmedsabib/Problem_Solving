#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = (int)1e5 + 5;
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(maxn + 1, false));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= maxn; j++) {
      dp[i][j] = dp[i - 1][j];
      int left = j - a[i - 1];
      if (left >= 0 && dp[i-1][left]) {
        dp[i][j] = 1;
      }
    }
  }
  vector<int> ans;
  for (int j = 1; j <= maxn; j++) {
    if (dp[n][j] == 1) {
      ans.push_back(j);
    }
  }
  cout << ans.size() << '\n';
  for (int v : ans) {
    cout << v << ' ';
  }
  cout << '\n';
}
