#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
 
int dp[maxn][2];
 
void precal() {
  dp[0][0] = 1;
  dp[0][1] = 1;
  for (int i = 1; i < maxn; ++i) {
    dp[i][0] = (2LL * dp[i - 1][0] + dp[i - 1][1])%mod;
    dp[i][1] = (4LL * dp[i - 1][1] + dp[i - 1][0])%mod;
  }
}
 
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  precal();
  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    int n;
    cin >> n;
    cout << (dp[n - 1][0] + dp[n - 1][1])%mod << '\n';
  }
  return 0;
}
