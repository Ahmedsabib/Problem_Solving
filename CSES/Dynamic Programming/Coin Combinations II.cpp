#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
 
long long dp[maxn];
 
// we will iterate through all possible w
// for each coin i while updating dp
// dp[w] = dp[w] + dp[w - coins[i]]
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  int n, k;
  cin >> n >> k;
  vector<long long> a(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (j - a[i - 1] >= 0) {
        dp[j] += dp[j - a[i - 1]];
        dp[j] %= mod;
      }
    }
  }
  cout << dp[k] << '\n';
  return 0;
}
