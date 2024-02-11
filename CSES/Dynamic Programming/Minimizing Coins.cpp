#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 5;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  vector<long long> coin(n);
  for (int i = 0; i < n; ++i) {
    cin >> coin[i];
  }
  vector<long long> dp(k + 1, inf);
  dp[0] = 0;
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i >= coin[j]) {
        dp[i] = min(dp[i], dp[i - coin[j]] + 1);
      }
    }
  }
  cout << (dp[k] == inf? -1 : dp[k]) << '\n';
  return 0;
}
