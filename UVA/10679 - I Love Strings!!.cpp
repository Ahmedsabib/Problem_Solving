#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> prefix_function(string s) {
  vector<ll> pi((int)s.size(), 0);
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
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    while (Q--) {
      string T;
      cin >> T;
      vector<ll> pref = prefix_function(T);
      int i = 0, j = 0, pos = -1;
      while (i < (int)S.size()) {
        if (S[i] == T[j]) {
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
        if (j == (int)T.size()) {
          pos = i - (int)T.size();
        }
      }
      cout << (pos == -1? "n\n" : "y\n");
    }
  }
  return 0;
}
