#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        long long sum = a[i] + a[j];
        long long index = upper_bound(a.begin(), a.end(), sum - 1) - a.begin();
        index--;
        if (index > j) {
          ans += index - j;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
