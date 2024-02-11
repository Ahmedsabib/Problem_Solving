#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long A, B, C, D; cin >> A >> B >> C >> D;
  cout << max(A*B, C*D) << '\n';
  return 0;
} 
