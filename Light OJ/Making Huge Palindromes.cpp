#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
  int n = (int)s.size();
  vector<int> pi(n, 0);
  for (int i = 1; i < n; ++i) {
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
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    string s;
    cin >> s;
    int n = (int)s.size();
    string t = s;
    reverse(t.begin(), t.end());
    s = t + '#' + s;
    vector<int> prefix = prefix_function(s);
    cout << 2 * n - prefix[(int)prefix.size() - 1] << '\n';
  }
  return 0;
}
