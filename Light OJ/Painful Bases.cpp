#include <bits/stdc++.h>

using namespace std;

#define int long long

int base, k, len;
string s;
int dp[1 << 17][25];

int bitmask_dp(int mask, int rem) {
  if (mask == (1 << len) - 1) return rem == 0;
  int &ret = dp[mask][rem];
  if (~ret) return ret;
  ret = 0;
  for (int i = 0; i < len; ++i) {
    if (mask & (1 << i)) continue;
    int dig = 0;
    if (s[i] >= '0' && s[i] <= '9') dig = s[i] - '0';
    else dig = (s[i] - 'A') + 10;
    ret += bitmask_dp(mask | (1 << i), (rem * base + dig)%k);
  }
  return ret;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    cin >> base >> k >> s;
    len = (int)s.size();
    memset(dp, -1, sizeof(dp));
    cout << bitmask_dp(0, 0) << '\n';
  }
  return 0;
}
