#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e4 + 9;
const int mod = 10000007;

int t, cs = 1;
ll a, b, c, d, e, f, n;
ll dp[maxn];

int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d >> e >> f >> n;
    dp[0] = a;
    dp[1] = b;
    dp[2] = c;
    dp[3] = d;
    dp[4] = e;
    dp[5] = f;
    for (int i = 6; i <= n; ++i) {
      dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6])%mod;
    }
    printf("Case %d: %lld\n", cs++, dp[n]%mod);
  }
  return 0;
}
