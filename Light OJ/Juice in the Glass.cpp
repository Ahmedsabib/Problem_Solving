#include <bits/stdc++.h>

using namespace std;

const double PI = 2.0 * acos(0.0);

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    double r1, r2, h, p;
    cin >> r1 >> r2 >> h >> p;
    double r3 = p/(h * 1.0) * (r1 - r2) + r2;
    double ans = (PI/3.0) * p * ((r3 * r3) + (r2 * r2) + (r3 * r2));
    cout << fixed << setprecision(10) << ans << '\n';
  }
  return 0;
}
