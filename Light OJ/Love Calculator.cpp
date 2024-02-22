#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 31;

int ans_str[maxn][maxn], uniq_str[maxn][maxn];

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    string s, t;
    cin >> s >> t;
    s = '#' + s;
    t = '#' + t;
    int n = (int)s.size(), m = (int)t.size();
    for (int i = 0; i < 31; ++i) {
      ans_str[i][0] = i;
      ans_str[0][i] = i;
      uniq_str[i][0] = 1;
      uniq_str[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (s[i] == t[j]) {
          ans_str[i][j] = 1 + ans_str[i - 1][j - 1];
          uniq_str[i][j] = uniq_str[i - 1][j - 1];
        }
        else {
          ans_str[i][j] = 1 + min(ans_str[i - 1][j], ans_str[i][j - 1]);
          if (ans_str[i][j - 1] == ans_str[i - 1][j]) {
            uniq_str[i][j] = uniq_str[i][j - 1] + uniq_str[i - 1][j];
          }
          else if (ans_str[i][j - 1] < ans_str[i - 1][j]) {
            uniq_str[i][j] = uniq_str[i][j - 1];
          }
          else {
            uniq_str[i][j] = uniq_str[i - 1][j];
          }
        }
      }
    }
    cout << ans_str[n - 1][m - 1] << ' ' << uniq_str[n - 1][m - 1] << '\n';
  }
  return 0;
}
