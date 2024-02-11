#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
  vector<int> pi((int)s.size(), 0);
  for (int i = 1; i < (int)s.size(); ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
        ++j;
    }
    pi[i] = j;
  }
  return pi;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    string s, t;
    cin >> s >> t;
    vector<int> pref = prefix_function(t);
    vector<int> ans;
    int i = 0, j = 0;
    while (i < (int)s.size()) {
      if (s[i] == t[j]) {
        ++i;
        ++j;
      }
      else {
        if (j != 0) {
          j = pref[j - 1];
        }
        else {
          ++i;
        }
      }
      if (j == (int)t.size()) {
        ans.push_back(i - ((int)s.size()));
      }
    }
    cout << (int)ans.size() << '\n';
  }
  return 0;
}
