#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  return b ? gcd(b, a%b) : a;
}
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    long long a, b, l;
    cin >> a >> b >> l;
    long long x = lcm(a, b);
    if (l%x != 0) {
      cout << "impossible\n";
    }
    else {
      long long c = l/x;
      long long g = gcd(c, x);
      while (g != 1) {
        c *= g;
        x /= g;
        g = gcd(c, x);
      }
      cout << c << '\n';
    }
  }
  return 0;
}
