#include <bits/stdc++.h>

using namespace std;

#define int long long

int dig[20], len;
int dp[20][2][2][20], tmp[20];

int digit_dp(int pos, int is_small, int is_started, int sz) {
  if (pos == 0) return 1;
  int &ret = dp[pos][is_small][is_started][sz];
  if (~ret) return ret;
  ret = 0;
  int low = 0, high = dig[pos];
  if (is_small) high = 9;
  for (int i = low; i <= high; ++i) {
    tmp[pos] = i;
    if (!is_started && i == 0) ret += digit_dp(pos - 1, 1, 0, sz - 1);
    else if (pos > sz/2 || tmp[pos] == tmp[sz - pos + 1]) {
      int new_is_small = is_small | (i < high);
      int val = digit_dp(pos - 1, new_is_small, 1, sz);
      ret += val;
    }
  }
  return ret;
}

int f(int n) {
  len = 0;
  while (n) {
    int rem = n%10;
    dig[++len] = rem;
    n /= 10;
  }
  memset(dp, -1, sizeof(dp));
  return digit_dp(len, 0, 0, len);
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    int x = f(b), y = f(a - 1);
    cout << x - y << '\n';
  }
  return 0;
}
