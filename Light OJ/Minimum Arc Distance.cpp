#include <bits/stdc++.h>

using namespace std;

double sqr(double x) {
  return x * x;
}

double dist(double x1, double y1, double x2, double y2) {
  double ans = sqr(x2 - x1) + sqr(y2 - y1);
  return sqrt(ans);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    double ox, oy, ax, ay, bx, by;
    cin >> ox >> oy >> ax >> ay >> bx >> by;
    double oa = 0.0, ob = 0.0, ab = 0.0;
    oa = dist(ox, oy, ax, ay);
    ob = dist(ox, oy, bx, by);
    ab = dist(ax, ay, bx, by);
    double x = 2 * oa * ob, y = (sqr(oa) + sqr(ob) - sqr(ab));
    double theta = acos(y/x);
    cout << fixed << setprecision(10) << oa * theta << '\n';
  }
  return 0;
}
