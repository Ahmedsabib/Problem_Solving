#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

int fact[maxn];

int binpow(int a, int b, int m) {
  a %= m;
  int res = 1;
  while (b > 0) {
    if (b&1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

int mod_inv(int a, int m) { return binpow(a, m - 2, m); }

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  fact[0] = fact[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    fact[i] = fact[i - 1]%mod * i;
    fact[i] %= mod;
  }

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    int a, b;
    cin >> a >> b;
    cout << ((fact[a] * mod_inv(fact[b] * fact[a - b], mod)))%mod << '\n';
  }
  return 0;
}
