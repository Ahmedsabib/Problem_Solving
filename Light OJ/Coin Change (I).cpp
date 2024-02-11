#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;
const int maxm = 1005;
const int mod = 100000007;

long long dp[maxn][maxm];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int n, k;
    cin >> n >> k;
    vector<long long> a(n + 1), lim(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
      cin >> lim[i];
    }
    for (int i = 0; i <= n; ++i) {
      for (int sum = 0; sum <= k; ++sum) {
        dp[i][sum] = 0;
      }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int sum = 0; sum <= k; ++sum) {
        dp[i][sum] = dp[i - 1][sum];
        for (int j = 1; j <= lim[i]; ++j) {
          if (sum < j * a[i]) {
            break;
          }
          long long res = dp[i - 1][sum - j * a[i]];
          dp[i][sum] = (dp[i][sum] + res)%mod;
        }
      }
    }
    cout << dp[n][k] << '\n';
  }
  return 0;
}
