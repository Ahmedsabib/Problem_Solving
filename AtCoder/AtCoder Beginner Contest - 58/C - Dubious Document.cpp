#include <bits/stdc++.h>

int main() {
  using namespace std;
  ios::sync_with_stdio(false); cin.tie(nullptr);
  
  int N; cin >> N;
  vector<vector<int>>freq(N, vector<int>(26, 0));
  for(int i = 0; i < N; ++i){
   string S; cin >> S;
   for(char c: S){
    freq[i][c-'a']++;
   }
  }
  for(int i = 0; i < 26; ++i){
   int mn = 1e9+8;
   for(int j = 0; j < N; ++j){
    mn = min(mn, freq[j][i]);
   }
   for(int j = 0; j < mn; ++j){
    cout << char('a'+i);
   }
  }
  cout << '\n';
  return 0;
}
