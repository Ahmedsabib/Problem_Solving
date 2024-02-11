#include <bits/stdc++.h>
using namespace std;
const int limit = (int)1e6 + 7;
// Time Complexity O(n log log n)
vector<bool> is_prime(limit+1, true); // define every number as prime
vector<long long> primes; // for storing the primes
void sieve_of_eratosthenes() {
  // Finding out the primes in simple way
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= limit; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= limit; j += i) {
        is_prime[j] = false;
      }
    }
  }
  // assigning values to an vector
  for (int i = 2; i <= limit; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}
long long divisors(long long n) {
  long long ans = 1, len = (int)primes.size();
  for (long long i = 0; i < len && (primes[i] * primes[i]) <= n; ++i) {
    long long power = 0;
    if (n%primes[i] == 0) {
      while (n%primes[i] == 0) {
        ++power;
        n /= primes[i];
      }
    }
    ans *= (power + 1);
  }
  if (n != 1) {
    ans <<= 1;
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  sieve_of_eratosthenes();
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    long long a, b;
    cin >> a >> b;
    long long root = sqrt(a);
    if (b * b == a || root < b) {
      cout << 0 << '\n';
      continue;
    }
    long long ans = divisors(a);
    ans /= 2;
    for (long long i = 1; i < b; ++i) {
      if (a%i == 0) {
        --ans;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
