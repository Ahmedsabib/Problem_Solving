#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N; cin >> N;
  long long x = 800*N;
  long long y = N/15;
  long long ans = x - (200*y);
  cout << ans << '\n';
  return 0;
}
