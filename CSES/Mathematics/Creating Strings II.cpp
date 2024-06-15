#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

int fact[maxn], inv[maxn];

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

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  factors();
  mod_inv();

  string s;
  cin >> s;
  int n = (int)s.size();
  map<char, int> mp;
  for (int i = 0; i < n; ++i) mp[s[i]]++;
  int ans = fact[n]%mod;
  for (auto& x: mp) {
    if (x.second > 1) {
      ans *= inv[x.second]%mod;
      ans %= mod;
    }
  }
  cout << ans << '\n';
  return 0;
}
