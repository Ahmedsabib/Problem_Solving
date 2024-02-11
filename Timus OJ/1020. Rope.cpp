#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926;
double dist(double x1, double y1, double x2, double y2) {
  double dx = x1 - x2;
  double dy = y1 - y2;
  return sqrt(dx * dx + dy * dy);
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  double r;
  cin >> n >> r;
  double xy[n][2], sum = 0.0;
  for (int i = 0; i < n; ++i) {
    cin >> xy[i][0] >> xy[i][1];
    if (i > 0) {
      sum += dist(xy[i][0], xy[i][1], xy[i - 1][0], xy[i - 1][1]);
    }
  }
  sum += dist(xy[0][0], xy[0][1], xy[n - 1][0], xy[n - 1][1]);
  sum += 2.00 * PI * r;
  cout << fixed << setprecision(2) << sum << '\n';
  return 0;
}
