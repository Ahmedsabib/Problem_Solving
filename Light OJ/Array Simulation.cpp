#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ":\n";
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    while (m--) {
      char ch;
      cin >> ch;
      if (ch == 'S') {
        int d;
        cin >> d;
        for (int i = 0; i < n; ++i) {
          a[i] += d;
        }
      }
      else if (ch == 'M') {
        int d;
        cin >> d;
        for (int i = 0; i < n; ++i) {
          a[i] *= d;
        }
      }
      else if (ch == 'D') {
        int d;
        cin >> d;
        for (int i = 0; i < n; ++i) {
          a[i] /= d;
        }
      }
      else if (ch == 'P') {
        int x, y;
        cin >> x >> y;
        swap(a[x], a[y]);
      }
      else if (ch == 'R') {
        reverse(a.begin(), a.end());
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
