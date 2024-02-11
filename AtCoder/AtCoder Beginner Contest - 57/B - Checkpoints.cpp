#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N, M; cin >> N >> M;
  long long A[51], B[51], C[51], D[51];
  for(int i = 0; i < N; ++i){
   cin >> A[i] >> B[i];
  }
  for(int i = 0; i < M; ++i){
   cin >> C[i] >> D[i];
  }
  long long ans;
  for(int i = 0; i < N; ++i){
   long long pos = -1, inf = 1e9+7;
   ans = 0;
   for(int j = 0; j < M; ++j){
    ans = abs(A[i] - C[j]) + abs(B[i] - D[j]);
    if(ans < inf){
     inf = ans;
     pos = j+1;
    }
   }
   cout << pos << '\n';
  }
  return 0;
}
