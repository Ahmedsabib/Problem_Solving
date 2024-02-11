#include <bits/stdc++.h>
using namespace std;
// iterative method
// (a^b)%m
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
    cout << "Case " << cs + 1 << ": ";
    long long n, k, m;
    cin >> n >> k >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
      sum = (sum + m)%m;
    }
    long long ans = (sum * (k%m))%m;
    ans = ans * binpow(n, k - 1, m);
    cout << (ans + m)%m << '\n';
  }
  return 0;
}
