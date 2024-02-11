#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int t[n];
  for(int i = 1; i <= n; ++i){
   cin >> t[i];
  }
  int m;
  cin >> m;
  int p[m], x[m];
  for(int i = 1; i <= m; ++i){
   cin >> p[i] >> x[i];
   int ans = 0;
   for(int j = 1; j <= n; ++j){
    if(p[i] == j){
     ans += x[i];
    }
    else ans += t[j];
   }
   cout << ans << '\n';
  }
  return 0;
}
