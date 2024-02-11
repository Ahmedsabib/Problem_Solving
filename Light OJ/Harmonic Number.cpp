#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 5;
const double G = 0.57721566490;
double a[maxn];
void precomp() {
  double ans = 0.0;
  for (int i = 1; i <= 1000000; ++i) {
    ans += 1.0/i;
    a[i] = ans;
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  precomp();
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    long long n;
    cin >> n;
    if (n <= 1000000) {
      cout << fixed << setprecision(10) << a[n] << '\n';
    }
    else {
      double ans, k;
      k = n + .5;
      ans = log(k) + G;
      cout << fixed << setprecision(10) << ans << '\n';
    }
  }
  return 0;
}
