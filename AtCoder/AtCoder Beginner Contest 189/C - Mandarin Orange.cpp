#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N; cin >> N;
   int A[N];
   for(int i = 0; i < N; ++i){
    cin >> A[i];
   }
   int ans = 0;
   for(int i = 0; i < N; ++i){
    int x = A[i];
    for(int j = i; j < N; ++j){
     x = min(x, A[j]);
     ans = max(ans, x*(j-i+1));
    }
   }
   cout << ans << '\n';
  return 0;
} 
 
