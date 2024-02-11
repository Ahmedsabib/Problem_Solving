#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N, M; cin >> N >> M;
  char A[N][N], B[M][M];
  for(int i = 0; i < N; ++i){
   for(int j = 0; j < N; ++j){
    cin >> A[i][j];
   }
  }
  for(int i = 0; i < M; ++i){
   for(int j = 0; j < M; ++j){
    cin >> B[i][j];
   }
  }
  int flag = 0;
  for(int i = 0; i <= N-M; ++i){
   for(int j = 0; j <= N-M; ++j){
    int ok = 0;
    for(int k = 0; k < M; ++k){
     for(int l = 0; l < M; ++l){
      if(A[i+k][j+l] == B[k][l]) ++ok;
     }
    }
    if(ok == M*M){
     flag = 1;
     break;
    }
   }
   if(flag){
    break;
   }
  }
  if(flag) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}
