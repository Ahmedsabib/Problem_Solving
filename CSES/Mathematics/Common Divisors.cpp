#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 5;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<long long> cnt(maxn, 0);
  for (int i = 0; i < n; ++i) {
    cnt[a[i]]++;
  }
  long long ans = 0;
  for (int i = maxn - 5; i >= 1; --i) {
    long long sum = 0;
    for (int j = i; j <= maxn - 5; j += i) {
      sum += cnt[j];
    }
    if (sum >= 2) {
      ans = i;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}
