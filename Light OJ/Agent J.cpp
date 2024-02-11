#include <bits/stdc++.h>

using namespace std;

double area(double r, double angle) {
  return 0.5 * r * r * angle;
}

double angle(double opp_a, double opp_b, double opp_c) {
  return acos(((opp_b * opp_b) + (opp_c * opp_c) - (opp_a * opp_a))/(2 * opp_b * opp_c));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    double a, b, c;
    cin >> a >> b >> c;
    double s = (a + a + b + b + c + c)/2.0;
    double total_area = sqrt(s * (s - a - b) * (s - b - c) * (s - c - a));
    total_area -= area(a, angle(b + c, c + a, a + b));
    total_area -= area(b, angle(c + a, a + b, b + c));
    total_area -= area(c, angle(a + b, b + c, c + a));
    cout << fixed << setprecision(10) << total_area << '\n';
  }
  return 0;
}
