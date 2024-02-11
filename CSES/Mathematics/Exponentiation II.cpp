#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b&1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    long long n, m, l;
    cin >> n >> m >> l;
    long long x = binpow(m, l, mod - 1);
    cout << binpow(n, x, mod) << '\n';
  }
  return 0;
}
