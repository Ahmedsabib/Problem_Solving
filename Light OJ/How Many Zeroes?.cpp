#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> dig;
int dp[12][2][2][70];

int digit_dp(int pos, int is_small, int is_started, int zero_cnt) {
  if (pos == (int)dig.size()) return zero_cnt;
  int &ret = dp[pos][is_small][is_started][zero_cnt];
  if (~ret) return ret;
  ret = 0;
  int low = 0, high = dig[pos];
  if (is_small) high = 9;
  if (!is_started) low = 1;
  for (int i = low; i <= high; ++i) {
    int new_is_small = is_small | (i < high);
    int val = digit_dp(pos + 1, new_is_small, 1, zero_cnt + (i == 0));
    ret += val;
  }
  if (!is_started) ret += digit_dp(pos + 1, 1, 0, 0);
  return ret;
}

int f(int n) {
  if (n < 0) return 0;
  if (n <= 9) return 1;
  dig.clear();
  while (n) {
    int rem = n%10;
    dig.push_back(rem);
    n /= 10;
  }
  reverse(dig.begin(), dig.end());
  memset(dp, -1, sizeof(dp));
  return digit_dp(0, 0, 0, 0) + 1; // extra 1, is for 0
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int a, b;
    cin >> a >> b;
    int x = f(b), y = f(a - 1);
    cout << x - y << '\n';
  }
  return 0;
}
