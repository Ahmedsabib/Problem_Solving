#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int maxn = (int)2e6 + 5;
long long fact[maxn];
void factor() {
  fact[0] = 1;
  for (long long i = 1; i < maxn; ++i) {
    fact[i] = (fact[i - 1]%mod * i)%mod;
  }
}
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
long long bin_inverse(long long a, long long m) {
  return binpow(a, m - 2, m);
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  factor();
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    int n, k;
    cin >> n >> k;
    long long ans = fact[n + k - 1];
    long long y = (fact[n] * fact[k - 1])%mod;
    ans = (ans * bin_inverse(y, mod));
    cout << ans%mod << '\n';
  }
  return 0;
}
