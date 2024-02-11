#include <bits/stdc++.h>
using namespace std;
long long cnt_of_number(long long n, long long x) {
  long long ans = 0;
  while (n > 0) {
    ans += n/x;
    n /= x;
  }
  return ans;
}
long long cnt_of_power(long long n, long long x) {
  long long ans = 0;
  while (n%x == 0) {
    ans++;
    n /= x;
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    long long n, r, p, q;
    cin >> n >> r >> p >> q;
    long long ans = 0;
    long long l = n - r;
    long long a = cnt_of_number(n, 2);
    long long b = cnt_of_number(n, 5);
    long long c = cnt_of_number(r, 2);
    long long d = cnt_of_number(r, 5);
    long long e = cnt_of_number(l, 2);
    long long f = cnt_of_number(l, 5);
    long long g = cnt_of_number(p, 2);
    long long h = cnt_of_number(p, 5);
    ans = min(a - c - e + (g * q), b - d - f + (h * q));
    cout << ans << '\n';
  }
  return 0;
}
