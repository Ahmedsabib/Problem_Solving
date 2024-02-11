#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
vector<long long> primes;
map<long long, long long> times;
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
long long inv_mod(long long n, long long m) {
  return binpow(n, m - 2, m);
}
void prime_divisors(long long n) {
  if (n%2 == 0) {
    primes.push_back(2);
    while (n%2 == 0) {
      n /= 2;
      times[2]++;
    }
  }
  for (long long d = 3; d * d <= n; d += 2) {
    if (n%d == 0) {
      primes.push_back(d);
      while (n%d == 0) {
        times[d]++;
        n /= d;
      }
    }
  }
  if (n > 1) {
    if (!times[n]) {
      primes.push_back(n);
    }
    times[n]++;
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    primes.clear();
    times.clear();
    long long n, m;
    cin >> n >> m;
    prime_divisors(n);
    for (auto& x: primes) {
      times[x] *= m;
    }
    long long ans = 1;
    for (auto& x: primes) {
      long long now = binpow(x, times[x] + 1, mod);
      now--;
      if (now < 0) {
        now += mod;
      }
      long long low = inv_mod(x - 1, mod);
      now *= low;
      ans = ((ans % mod) * (now % mod)) % mod;
    }
    cout << ans << '\n';
  }
  return 0;
}
