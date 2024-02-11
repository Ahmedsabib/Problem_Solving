#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N; cin >> N;
  long long ans = 1;
  long long MOD = 1e9+7;
  for(long long i = 1; i <= N; ++i){
   ans *= i;
   ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}
