#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e3 + 5;
const int mod = 10056;

int cnt[maxn], ans[maxn];

void precompute() {
  cnt[1] = 1;
  ans[1] = 1;
  int sum = 0;
  for (int i = 2; i <= maxn; ++i) {
    sum = 1;
    for (int j = i; j >= 2; --j) {
      cnt[j] = (cnt[j] * j)%mod + (cnt[j - 1] * j)%mod;
      cnt[j] %= mod;
      sum += cnt[j];
      sum %= mod;
    }
    ans[i] = sum;
    ans[i] %= mod;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  precompute();

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int n;
    cin >> n;
    cout << ans[n] << '\n';
  }
  return 0;
}
