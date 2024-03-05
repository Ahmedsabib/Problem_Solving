#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 55;

string s;
int len = 0;
string dp[maxn][maxn][maxn];

int f(char ch) {
  return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

string check(int pos, int cnt_v, int cnt_c) {
  if (cnt_v == 3 || cnt_c == 5) return "BAD";
  if (pos >= len) return "GOOD";
  string &ret = dp[pos][cnt_v][cnt_c];
  if (ret != "") return ret;
  ret = "";
  if (s[pos] == '?') {
    string x = check(pos + 1, 0, cnt_c + 1);
    string y = check(pos + 1, cnt_v + 1, 0);
    if (x != y || x == "MIXED" || y == "MIXED") ret = "MIXED";
    else ret = x;
  }
  else if (!f(s[pos])) ret = check(pos + 1, 0, cnt_c + 1);
  else ret = check(pos + 1, cnt_v + 1, 0);
  return ret;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    cin >> s;
    len = (int)s.size();
    for (int i = 0; i < maxn; ++i) {
      for (int j = 0; j < maxn; ++j) {
        for (int k = 0; k < maxn; ++k) {
          dp[i][j][k] = "";
        }
      }
    }
    cout << check(0, 0, 0) << '\n';
  }
  return 0;
}
