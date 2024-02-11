#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N, x; cin >> N >> x;
  long long sum = 0, ans = -1, ok = 0;
  for(int i = 1; i <= N; ++i){
   long long y, z;
   cin >> y >> z;
   long long r = (y*z);
   sum += r;
   if(sum > x*100){
    ans = i;
    ok = 1;
    break;
   }
  }
  if(ok) cout << ans << '\n';
  else cout << -1 << '\n';
  return 0;
} 
 
