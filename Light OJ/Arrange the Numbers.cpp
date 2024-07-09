#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;

int fact[maxn], inv[maxn], dar[maxn];

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

void factors() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    fact[i] = fact[i - 1]%mod * i%mod;
    fact[i] %= mod;
  }
}

void mod_inv() {
  inv[maxn - 1] = binpow(fact[maxn - 1], mod - 2, mod);
  for (int i = maxn - 1; i >= 1; --i) {
    inv[i - 1] = inv[i]%mod * i;
    inv[i - 1] %= mod;
  }
}

int ncr(int n, int k) {
  if (k > n) return 0;
  return (fact[n]%mod * inv[k]%mod * inv[n - k]%mod)%mod;
}

void derangemnets() {
  dar[0] = 1;
  dar[1] = 0;
  dar[2] = 1;
  for (int i = 3; i <= maxn; ++i) {
    dar[i] = (dar[i - 2]%mod + dar[i - 1]%mod)%mod * (i - 1)%mod;
    dar[i] %= mod;
  }
}

void precompute() {
  factors();
  mod_inv();
  derangemnets();
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  precompute();

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int n, m, k;
    cin >> n >> m >> k;
    int res = ncr(m, k)%mod, ans = 0;
    for (int i = 0; i <= n - m; ++i) {
      ans = (ans%mod + (ncr(n - m, i)%mod * dar[n - i - k]%mod)%mod)%mod;
      ans %= mod;
    }
    cout << (ans%mod * res%mod)%mod << '\n';
  }
  return 0;
}
