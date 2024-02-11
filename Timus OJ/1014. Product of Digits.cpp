#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long n;
  cin >> n;
  if (n == 0) {
    cout << 10 << '\n';
    return 0;
  }
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  vector<long long> ans;
  for (int i = 9; i >= 2; --i) {
    if (n%i == 0) {
      while (n%i == 0) {
        n /= i;
        ans.push_back(i);
      }
    }
  }
  if (n == 1) {
    reverse(ans.begin(), ans.end());
    for (auto& x: ans) {
      cout << x;
    }
    cout << '\n';
  }
  else {
    cout << -1 << '\n';
  }
  return 0;
}
