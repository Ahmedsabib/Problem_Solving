#include <bits/stdc++.h>

using namespace std;

// the key idea is the ways are..
// n*n + (n - 1)*(n - 1) + (n - 2)*(n - 2)
// as the constrainsts are up to 10^14
// we can not calculate in brute force
// after optimizing we find an equation
// (nck)*(nck)*k!
// we can do this in dynamic programming

long long dp[32][32], fact[32];

long long ncr(long long n, long long r) {
  if (n == r || r == 0) {
    return 1;
  }
  if (dp[n][r] != -1) {
    return dp[n][r];
  }
  dp[n][r] = ncr(n - 1, r) + ncr(n - 1, r - 1);
  return dp[n][r];
}

void precal() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i < 32; ++i) {
    fact[i] = i * fact[i - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  precal();
  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    memset(dp, -1, sizeof(dp));
    long long n, k;
    cin >> n >> k;
    if (k == 1) {
      cout << n * n << '\n';
    }
    else if (n < k) {
      cout << 0 << '\n';
    }
    else {
      long long res = ncr(n, k);
      cout << res * res * fact[k] << '\n';
    }
  }
  return 0;
}
