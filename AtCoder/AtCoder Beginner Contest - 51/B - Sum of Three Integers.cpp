#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  int ans = 0;
  for(int i = 0; i <= N; ++i){
   for(int j = 0; j <= N; ++j){
    int r = K - (i + j);
    if(r <= N and r >= 0) ++ans;
   }
  }
  cout << ans << '\n';
  return 0;
}
