#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 3;
const int mod = (int)1e6 + 3;
long long fact[maxn];
void precomp() {
  fact[0] = 1;
  for (long long i = 1; i < maxn; ++i) {
    fact[i] = ((i%mod) * (fact[i - 1]%mod))%mod;
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
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  precomp();
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    long long a, b;
    cin >> a >> b;
    long long x = ((fact[b]%mod) * (fact[a - b]%mod))%mod;
    long long y = binpow(x, mod - 2, mod);
    long long z = ((fact[a]%mod) * (y%mod))%mod;
    cout << z << '\n';
  }
  return 0;
}
