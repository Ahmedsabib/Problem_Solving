#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  char x, y, z; cin >> x >> y >> z;
  if(x == y and y == z) cout << "Won" << '\n';
  else cout << "Lost" << '\n';
  return 0;
} 
 
