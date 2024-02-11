#include <bits/stdc++.h>
 
using namespace std;
 
int N = 8, cnt = 0;
int col[16], dia1[16], dia2[16], reserve[8][8];
 
void search(int y){
 if(y == N){
  ++cnt;
  return;
 }
 for(int x = 0; x < N; ++x){
  if(col[x] || dia1[x+y] || dia2[x-y+N-1] || reserve[y][x]) continue;
  col[x] = dia1[x+y] = dia2[x-y+N-1] = 1;
  search(y+1);
  col[x] = dia1[x+y] = dia2[x-y+N-1] = 0;
 }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for(int i = 0; i < 16; ++i){
   col[i] = dia1[i] = dia2[i] = 0;
  }
  string S;
  for(int i = 0; i < N; ++i){
   cin >> S;
   for(int j = 0; j < 8; ++j){
    reserve[i][j] = S[j] != '.';
   }
  }
  search(0);
  cout << cnt << '\n';
  return 0;
}
