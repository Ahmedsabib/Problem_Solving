#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const int mod = 1e8 + 7;

int fact[maxn], inv[maxn];
vector<int> p;

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
    fact[i] = fact[i - 1]%mod * i;
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
  return (fact[n] * inv[k]%mod * inv[n - k]%mod)%mod;
}

void precompute() {
  factors();
  mod_inv();
  for (int i = 2; i <= maxn; ++i) {
    for (int j = i * i; j <= 1e10; j *= i) p.push_back(j);
  }
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  precompute();

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int a, b;
    cin >> a >> b;
    int n = (upper_bound(p.begin(), p.end(), b) - p.begin()) - (lower_bound(p.begin(), p.end(), a) - p.begin());
    cout << (n == 0? 0 : fact[2 * n]%mod * inv[n + 1]%mod * inv[n]%mod) << '\n';
  }
  return 0;
}
