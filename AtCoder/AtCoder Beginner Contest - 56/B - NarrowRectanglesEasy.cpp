#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, a, b; cin >> w >> a >> b;
  if(a <= b and b <= a+w) cout << 0 << '\n';
  else if(b <= a and a <= b+w) cout << 0 << '\n';
  else cout << min(abs(b-w-a), abs(b+w-a)) << '\n';
  return 0;
}
