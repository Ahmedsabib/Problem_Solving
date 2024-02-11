#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ":\n";
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int q;
    cin >> q;
    while (q--) {
      int x, y;
      cin >> x >> y;
      if ((x >= x1 && x <= x2) && (y >= y1 && y <= y2)) {
        cout << "Yes\n";
      }
      else {
        cout << "No\n";
      }
    }
  }
  return 0;
}
