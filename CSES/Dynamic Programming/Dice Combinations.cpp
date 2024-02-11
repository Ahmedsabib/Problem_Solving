#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 5;
const int mod = (int)1e9 + 7;
int dp[maxn];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<int> a = {1, 2, 3, 4, 5, 6};
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (auto& x: a) {
      if (i >= x) {
        dp[i] = (dp[i] + dp[i - x])%mod;
      }
    }
  }
  cout << (dp[n]%mod) << '\n';
  return 0;
}
