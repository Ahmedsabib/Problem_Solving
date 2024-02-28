#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 85;

int a, b, k;
vector<int> dig;
int dp[10][maxn][maxn][2];

int digit_dp(int pos, int digit_sum_rem, int digit_rem, int is_small) {
  if (pos == (int)dig.size()) return ((digit_rem + digit_sum_rem) == 0);
  int &ret = dp[pos][digit_sum_rem][digit_rem][is_small];
  if (~ret) return ret;
  ret = 0;
  int low = 0, high = dig[pos];
  if (is_small) high = 9;
  for (int i = low; i <= high; ++i) {
    int new_small = is_small | (i < high);
    int val = digit_dp(pos + 1, ((digit_sum_rem * 10) + i)%k, (digit_rem + i)%k, new_small);
    ret += val;
  }
  return ret;
}

int f(int x) {
  dig.clear();
  while (x > 0) {
    int res = x%10;
    dig.push_back(res);
    x /= 10;
  }
  reverse(dig.begin(), dig.end());
  memset(dp, -1, sizeof(dp));
  return digit_dp(0, 0, 0, 0);
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    cin >> a >> b >> k;
    if (k == 1) cout << b - a + 1 << '\n';
    else if (k > 81) cout << "0\n";
    else {
      memset(dp, -1, sizeof(dp));
      int x = f(b);
      memset(dp, -1, sizeof(dp));
      int y = f(a - 1);
      cout << x - y << '\n';
    }
  }
  return 0;
}
