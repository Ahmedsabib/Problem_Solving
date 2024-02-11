#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e8 + 9;
const int max_n = (int)6e6 + 9;
unsigned int mul[max_n], primes[maxn];
bitset<maxn> is_prime;
int len = 0;
void sieve_of_eratosthenes() {
  is_prime[0] = is_prime[1] = 1;
  int lim = sqrt(maxn * 1.0) + 2;
  primes[len++] = 2;
  for (int i = 4; i < maxn; i += 2) {
    is_prime[i] = 1;
  }
  for (int i = 3; i < maxn; i += 2) {
    if (!is_prime[i]) {
      primes[len++] = i;
      if (i <= lim) {
        for (int j = i * i; j <= maxn; j += i) {
          is_prime[j] = 1;
        }
      }
    }
  }
}
void precomp() {
  mul[0] = 2;
  for (int i = 1; i < len; ++i) {
    mul[i] = (primes[i] * mul[i - 1]);
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  sieve_of_eratosthenes();
  precomp();
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    int n;
    cin >> n;
    unsigned int ans = 1;
    int ind = upper_bound(primes, primes + len, n) - primes;
    ind--;
    ans *= mul[ind];
    for (int i = 0; i < len; ++i) {
      long long p = primes[i];
      long long x = n;
      long long cnt = 0;
      if (p * p > n) {
        break;
      }
      while (x >= p) {
        x /= p;
        ++cnt;
      }
      ans *= pow(p, cnt - 1);
    }
    cout << ans << '\n';
  }
  return 0;
}
