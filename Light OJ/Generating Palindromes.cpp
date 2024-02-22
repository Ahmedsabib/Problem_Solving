#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18;
const int maxn = 102;

int dp[maxn][maxn];
string s;

int check(int x, int len) {
  if (x >= len) return 0;
  if (dp[x][len] != -1) return dp[x][len];
  int ans = inf;
  if (s[x] == s[len]) ans = min(ans, check(x + 1, len - 1));
  else ans = min(ans, 1 + min(check(x + 1, len), check(x, len - 1)));
  return dp[x][len] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    cin >> s;
    int n = (int)s.size();
    memset(dp, -1, sizeof(dp));
    cout << check(0, n - 1) << '\n';
  }
  return 0;
}
