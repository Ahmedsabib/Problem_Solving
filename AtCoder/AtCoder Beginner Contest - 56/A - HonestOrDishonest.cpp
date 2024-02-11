#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  char N, M; cin >> N >> M;
  if(N == 'D'){
   if(M == 'D') cout << 'H';
   else cout << 'D';
  }
  else cout << M;
  return 0;
}
