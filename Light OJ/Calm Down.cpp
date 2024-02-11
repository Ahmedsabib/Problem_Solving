#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    double r, n;
    cin >> r >> n;
    double angle = PI/n;
    double ans = (r * sin(angle))/(1 + sin(angle));
    cout << fixed << setprecision(10) << ans << '\n';
  }
  return 0;
}
