#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  vector<long long> coin(n);
  for (int i = 0; i < n; ++i) {
    cin >> coin[i];
  }
  vector<long long> dp(k + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i >= coin[j]) {
        dp[i] += dp[i - coin[j]];
        dp[i] %= mod;
      }
    }
  }
  cout << dp[k] << '\n';
  return 0;
}
