#include <bits/stdc++.h>
using namespace std;
double check(double a, double b, double mid) {
  double x = sqrt((a * a) - (mid * mid));
  double y = sqrt((b * b) - (mid * mid));
  double res = (x * y)/(x + y);
  return res;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    double a, b, c;
    cin >> a >> b >> c;
    double low = 0, high = min(a, b), ans = 0.0;
    while (high - low > 0.0000001) {
      double mid = low + (high - low)/2;
      if (check(a, b, mid) <= c) {
        ans = mid;
        high = mid;
      }
      else {
        low = mid;
      }
    }
    cout << fixed << setprecision(10) << ans << '\n';
  }
  return 0;
}
