#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n], c[n+1];
  long long mod = 1000000007;
  for(int i = 0; i < n; ++i){
   cin >> a[i];
  }
  for(int i = 0; i < n+1; ++i){
   c[i] = 0;
  }
  bool flag = true;
  for(int i = 0; i < n; ++i){
   if(n%2 == a[i]%2) flag = false;
   if(a[i] == 0){
    if(c[0] >= 1) flag = false;
    c[0]++;
   }
   else{
    if(c[a[i]] >= 2) flag = false;
    c[a[i]]++;
   }
  }
  if(!flag) cout << 0 << '\n';
  else{
   long long ans = 1;
   for(int i = 0; i < n/2; ++i){
    ans *= 2;
    ans %= mod;
   }
   cout << ans << '\n';
  }
  return 0;
}
