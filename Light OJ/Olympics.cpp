#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    double a, b;
    char c;
    cin >> a >> c >> b;
    double radius = sqrt(a * a + b * b)/2.0;
    double theta = acos((2.0 * radius * radius - b * b)/(2.0 * radius * radius));
    double s = radius * theta;
    double x = 400.0/(2 * a + 2 * s);
    double length = x * a, width = x * b;
    cout << fixed << setprecision(10) << length << ' ' << width << '\n';
  }
  return 0;
}
