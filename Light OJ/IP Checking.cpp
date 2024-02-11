#include <bits/stdc++.h>

using namespace std;

string check(string s) {
  int t = 0;
  int d = 0;
  for (int i = (int)s.size() - 1; i >= 0; --i) {
    t += ((s[i] - '0') * (1 << d++));
  }
  return to_string(t);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    string s, t;
    cin >> s >> t;
    s += '.';
    t += '.';
    vector<string> a(4), b(4);
    int d = 0;
    string ss;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == '.') {
        a[d++] = ss;
        ss = "";
      }
      else {
        ss += s[i];
      }
    }
    d = 0;
    ss = "";
    for (int i = 0; i < (int)t.size(); ++i) {
      if (t[i] == '.') {
        b[d++] = ss;
        ss = "";
      }
      else {
        ss += t[i];
      }
    }
    int ok = 0;
    for (int i = 0; i < 4; ++i) {
      string x = check(b[i]);
      if (x != a[i]) {
        ok = 1;
      }
    }
    cout << (ok? "No\n" : "Yes\n");
  }
  return 0;
}
