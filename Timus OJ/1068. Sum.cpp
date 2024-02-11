#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  long long ans = 0;
  if (n > 0) {
    for (int i = 1; i <= n; ++i) {
      ans += i;
    }
  }
  else {
    for (int i = n; i <= 1; ++i) {
      ans += i;
    }
  }
  cout << ans << '\n';
  return 0;
}
