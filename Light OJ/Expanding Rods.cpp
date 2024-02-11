#include <bits/stdc++.h>
using namespace std;
double check(double mid, double l) {
  double radius = (mid/2.0) + ((l * l)/(8.0 * mid));
  double theta = 2.0 * asin((l/2.0)/radius);
  double s = radius * theta;
  return s;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    double l, r, c;
    cin >> l >> r >> c;
    double low = 0.0, high = l, mid;
    double s = (1.0 + (r * c)) * l;
    for (int i = 0; i < 60; ++i) {
      mid = low + (high - low)/2.0;
      if (check(mid, l) >= s) {
        high = mid;
      }
      else {
        low = mid;
      }
    }
    cout << fixed << setprecision(10) << mid << '\n';
  }
  return 0;
}
