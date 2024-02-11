#include <bits/stdc++.h>

using namespace std;

map<long long,long long>dp;
long long MOD = 1e9+7;

long long dfs(long long x){
  if(dp[x]) return dp[x];
  return dp[x] = (dfs(x/2) + dfs((x-1)/2) + dfs((x-2)/2))% MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N;
  cin >> N;
  dp[0] = 1, dp[1] = 2;
  cout << dfs(N) << '\n';
  return 0;
}
