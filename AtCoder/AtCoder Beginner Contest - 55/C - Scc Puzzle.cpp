#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N, M; cin >> N >> M;
  M /= 2;
  if(M < N) cout << M << '\n';
  else{
   long long ans = 0;
   M -= N;
   ans += N;
   M /= 2;
   ans += M;
   cout << ans << '\n';
  }
  return 0;
}
