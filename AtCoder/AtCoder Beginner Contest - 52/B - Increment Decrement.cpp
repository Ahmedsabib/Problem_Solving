#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  string S; cin >> S;
  int ans = 0, best = 0;
  for(int i = 0; i < N; ++i){
   if(S[i] == 'I') ++ans;
   else --ans;
   best = max(best, ans);
  }
  cout << best << '\n';
  return 0;
} 
