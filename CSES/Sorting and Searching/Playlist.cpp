#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<long long, long long> mp;
  long long j = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    j = max(mp[a[i]], j);
    ans = max(ans, i - j + 1);
    mp[a[i]] = i + 1;
  }
  cout << ans << '\n';
  return 0;
}
