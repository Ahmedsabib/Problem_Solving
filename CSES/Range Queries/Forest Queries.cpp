#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1000;

int forest[maxn + 1][maxn + 1], tree_pref[maxn + 1][maxn + 1];

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char ch;
      cin >> ch;
      forest[i + 1][j + 1] += (ch == '*');
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      tree_pref[i][j] = forest[i][j] + tree_pref[i - 1][j] + tree_pref[i][j - 1] - tree_pref[i - 1][j - 1];
    }
  }
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << tree_pref[x2][y2] - tree_pref[x1 - 1][y2] - tree_pref[x2][y1 - 1] + tree_pref[x1 - 1][y1 - 1] << '\n';
  }
  return 0;
}
