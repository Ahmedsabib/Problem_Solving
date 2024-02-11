#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
    long long n;
    cin >> n;
    vector<long long>a(n);
    for(int i = 0; i < n; ++i){
     cin >> a[i];
    }
    long long cnt = 0, ans = 0;
    for(long long i = 1; i < n; ++i){
     if(a[i-1]+cnt > a[i]){
      int r = a[i-1]+cnt;
      cnt = 0;
      cnt = (r-a[i]);
     }
     else{
      cnt = 0;
     }
     ans += cnt;
    }
    cout << ans << '\n';
  return 0;
}
